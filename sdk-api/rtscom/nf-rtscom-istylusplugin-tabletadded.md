# IStylusPlugin::TabletAdded

## Description

Notifies an implementing plug-in when an [ITablet](https://learn.microsoft.com/windows/desktop/tablet/itablet) object is attached to the system.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `piTablet` [in]

 The added tablet object.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is called by the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object, whether the **RealTimeStylus Class** object is enabled or disabled.

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::TabletRemoved Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-tabletremoved)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)