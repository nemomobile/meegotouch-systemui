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
#ifndef WIDGETNOTIFICATIONSINK_STUB
#define WIDGETNOTIFICATIONSINK_STUB

#include "widgetnotificationsink.h"
#include <stubbase.h>


// 1. DECLARE STUB
// FIXME - stubgen is not yet finished
class WidgetNotificationSinkStub : public StubBase
{
public:
    virtual void notificationRemovalRequested(uint notificationId);
    virtual void notificationGroupClearingRequested(uint groupId);
    virtual QString determineIconId(const NotificationParameters &parameters);
    virtual MBanner *createInfoBanner(const Notification &notification);
    virtual MBanner *createInfoBanner(Notification::NotificationType type, uint groupId, const NotificationParameters &parameters);
    virtual void updateActions(MBanner *infoBanner, const NotificationParameters &parameters);
    virtual QString determineIconIdFromEventType(const QString &eventType);
    virtual void infoBannerClicked();
};

// 2. IMPLEMENT STUB
void WidgetNotificationSinkStub::notificationRemovalRequested(uint notificationId)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<uint >(notificationId));
    stubMethodEntered("notificationRemovalRequested", params);
}

void WidgetNotificationSinkStub::notificationGroupClearingRequested(uint groupId)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<uint >(groupId));
    stubMethodEntered("notificationGroupClearingRequested", params);
}

QString WidgetNotificationSinkStub::determineIconId(const NotificationParameters &parameters)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<const NotificationParameters & >(parameters));
    stubMethodEntered("determineIconId", params);
    return stubReturnValue<QString>("determineIconId");
}

MBanner *WidgetNotificationSinkStub::createInfoBanner(const Notification &notification)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<const Notification & >(notification));
    stubMethodEntered("createInfoBanner", params);
    return stubReturnValue<MBanner *>("createInfoBanner");
}

MBanner *WidgetNotificationSinkStub::createInfoBanner(Notification::NotificationType type, uint groupId, const NotificationParameters &parameters)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<Notification::NotificationType >(type));
    params.append(new Parameter<uint >(groupId));
    params.append(new Parameter<const NotificationParameters & >(parameters));
    stubMethodEntered("createInfoBanner", params);
    return stubReturnValue<MBanner *>("createInfoBanner");
}

void WidgetNotificationSinkStub::updateActions(MBanner *infoBanner, const NotificationParameters &parameters)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<MBanner * >(infoBanner));
    params.append(new Parameter<const NotificationParameters & >(parameters));
    stubMethodEntered("updateActions", params);
}

QString WidgetNotificationSinkStub::determineIconIdFromEventType(const QString &eventType)
{
    QList<ParameterBase *> params;
    params.append(new Parameter<const QString & >(eventType));
    stubMethodEntered("determineIconIdFromEventType", params);
    return stubReturnValue<QString>("determineIconIdFromEventType");
}

void WidgetNotificationSinkStub::infoBannerClicked()
{
    stubMethodEntered("infoBannerClicked");
}



// 3. CREATE A STUB INSTANCE
WidgetNotificationSinkStub gDefaultWidgetNotificationSinkStub;
WidgetNotificationSinkStub *gWidgetNotificationSinkStub = &gDefaultWidgetNotificationSinkStub;


// 4. CREATE A PROXY WHICH CALLS THE STUB
const char *WidgetNotificationSink::USER_REMOVABLE_PROPERTY = "userRemovable";
QString WidgetNotificationSink::determineIconId(const NotificationParameters &parameters)
{
    return gWidgetNotificationSinkStub->determineIconId(parameters);
}

MBanner *WidgetNotificationSink::createInfoBanner(const Notification &notification)
{
    return gWidgetNotificationSinkStub->createInfoBanner(notification);
}

MBanner *WidgetNotificationSink::createInfoBanner(Notification::NotificationType type, uint groupId, const NotificationParameters &parameters)
{
    return gWidgetNotificationSinkStub->createInfoBanner(type, groupId, parameters);
}

void WidgetNotificationSink::updateActions(MBanner *infoBanner, const NotificationParameters &parameters)
{
    gWidgetNotificationSinkStub->updateActions(infoBanner, parameters);
}

QString WidgetNotificationSink::determineIconIdFromEventType(const QString &eventType)
{
    return gWidgetNotificationSinkStub->determineIconIdFromEventType(eventType);
}

void WidgetNotificationSink::infoBannerClicked()
{
    gWidgetNotificationSinkStub->infoBannerClicked();
}


#endif
