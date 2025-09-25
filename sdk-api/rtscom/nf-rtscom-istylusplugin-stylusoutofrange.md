# IStylusPlugin::StylusOutOfRange

## Description

Notifies the implementing plug-in that the stylus has left the detection range of the digitizer.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `tcid` [in]

Tablet context identifier.

### `sid` [in]

Stylus identifier.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The stylus is out of range of the digitizer.

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)