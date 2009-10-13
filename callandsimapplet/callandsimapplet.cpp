#include "callandsimapplet.h"
#include "callandsimtranslation.h"
#include "callandsimbrief.h"
#include "callandsimwidget.h"
#include "dcpcallandsim.h"

#include <DuiTheme>
#include <DuiAction>

Q_EXPORT_PLUGIN2(callandsimapplet, CallAndSimApplet)

namespace DcpCallAndSim
{
    const QString css("/usr/share/duicontrolpanel/themes/style/networkapplet.css");
}

void CallAndSimApplet::init(QString part)
{
    Q_UNUSED(part);
    DuiTheme::loadCSS(DcpCallAndSim::css);
}

DcpWidget* CallAndSimApplet::constructWidget(int widgetId)
{
    switch (widgetId) {
        case DcpCallAndSim::Main:
            return pageMain();
        break;
    }

    return 0;
}

DcpWidget* CallAndSimApplet::pageMain()
{
    if (main.isNull()) {
        main = new CallAndSimWidget();
    }

    return main;
}

QString CallAndSimApplet::title() const
{
    return DcpCallAndSim::CallAndSimText;
}

QVector<DuiAction*> CallAndSimApplet::viewMenuItems()
{
    QVector<DuiAction*> vector;
//    DuiAction* helpAction = new DuiAction(DcpProfile::MenuHelpText, pageMain());
//    vector.append(helpAction);
    return vector;
}

DcpBrief* CallAndSimApplet::constructBrief()
{
    return new CallAndSimBrief();
}

