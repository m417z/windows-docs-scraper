# IStylusPlugin::UpdateMapping

## Description

Notifies the plug-in when display properties, such as dpi or orientation, change.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is called when display properties, such as dpi or orientation, change. Call the [IRealTimeStylus::GetAllTabletContextIds Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getalltabletcontextids) method to get more information about the change.

The **IStylusPlugin::UpdateMapping Method** method provides a mechanism for applications to determine when tablet display properties change. This method is called on [WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange) messages.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::DataInterest Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-datainterest)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)