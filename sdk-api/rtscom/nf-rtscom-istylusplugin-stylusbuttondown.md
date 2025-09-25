# IStylusPlugin::StylusButtonDown

## Description

Notifies the implementing plug-in that the user is pressing a stylus button.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that sent the notification.

### `sid` [in]

Security identifier.

### `pGuidStylusButton` [in]

The GUID-type identifier for the stylus button data. The GUID indicates the unique identifier for this data object.

### `pStylusPos` [in, out]

A [StylusInfo Structure](https://learn.microsoft.com/windows/desktop/api/rtscom/ns-rtscom-stylusinfo) containing the information about the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object that is associated with the stylus.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This notification is used to when the stylus button is down and the stylus is in range of the digitizer.

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)