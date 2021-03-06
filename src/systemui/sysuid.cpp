/****************************************************************************
 **
 ** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (directui@nokia.com)
 **
 ** This file is part of systemui.
 **
 ** If you have questions regarding the use of this file, please contact
 ** Nokia at directui@nokia.com.
 **
 ** This library is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License version 2.1 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.LGPL included in the packaging
 ** of this file.
 **
 ****************************************************************************/

#include <MLocale>
#include <MTheme>
#include <MLocale>
#include <MApplicationExtensionArea>
#include <QDBusConnection>

#include "sysuid.h"
#include "statusarearendereradaptor.h"
#include "statusareastyle.h"
#include "statusarearenderer.h"
#include "statusindicatormenubusinesslogic.h"
#include "statusindicatormenuadaptor.h"
#include "contextframeworkcontext.h"
#include "closeeventeater.h"
#include "diskspacenotifier.h"
#include <QX11Info>

Sysuid* Sysuid::instance_ = NULL;

static const char *SYSTEMUI_DBUS_SERVICE = "com.nokia.systemui";
static const char *SYSTEMUI_DBUS_PATH = "/";

Sysuid::Sysuid(QObject* parent) : QObject(parent)
{
    instance_ = this;

    // Load translations of System-UI
    loadTranslations();

    // D-Bus registration
    QDBusConnection bus = QDBusConnection::sessionBus();
    if (!bus.registerService(SYSTEMUI_DBUS_SERVICE)) {
        qCritical("Unable to register system-ui D-Bus service %s: %s", SYSTEMUI_DBUS_SERVICE, bus.lastError().message().toUtf8().constData());
        abort();
    }
    if (!bus.registerObject(SYSTEMUI_DBUS_PATH, instance())) {
        qCritical("Unable to register system-ui object at path %s: %s", SYSTEMUI_DBUS_PATH, bus.lastError().message().toUtf8().constData());
        abort();
    }

    const StatusAreaStyle *style = static_cast<const StatusAreaStyle *>(MTheme::style("StatusAreaStyle"));
    if (style->statusAreaEnabled()) {
        // Create a status area renderer for rendering the shared status area pixmap
        statusAreaRenderer = new StatusAreaRenderer(this);
        new StatusAreaRendererAdaptor(statusAreaRenderer);
        bus.registerService("com.meego.core.MStatusBar");
        bus.registerObject("/statusbar", statusAreaRenderer);
    }
    MTheme::releaseStyle(style);

    // Create a status indicator menu
    statusIndicatorMenuBusinessLogic = new StatusIndicatorMenuBusinessLogic(this);
    new StatusIndicatorMenuAdaptor(statusIndicatorMenuBusinessLogic);
    bus.registerService("com.meego.core.MStatusIndicatorMenu");
    bus.registerObject("/statusindicatormenu", statusIndicatorMenuBusinessLogic);

    // Create components that may create or remove notifications
    new DiskSpaceNotifier(this);
}

Sysuid::~Sysuid()
{
    instance_ = 0;
}

Sysuid* Sysuid::instance()
{
    return instance_;
}

void Sysuid::loadTranslations()
{
    MLocale locale;

    // Install real translations
    locale.installTrCatalog("usb");
    locale.installTrCatalog("reset");
    locale.installTrCatalog("profiles");
    locale.installTrCatalog("status");
    locale.installTrCatalog("connectivity");
    locale.installTrCatalog("memory-usage");
    locale.installTrCatalog("cellular-adaptation");

    // and the engineering english ones
    locale.installTrCatalog("systemui");

    MLocale::setDefault(locale);
}
