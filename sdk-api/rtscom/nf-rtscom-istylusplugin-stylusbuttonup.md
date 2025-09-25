# IStylusPlugin::StylusButtonUp

## Description

Notifies the implementing plug-in that the user has released a stylus button.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `sid` [in]

Security identifier.

### `pGuidStylusButton` [in]

The globally unique identifier (GUID) for the stylus button data.

### `pStylusPos` [in, out]

A[StylusInfo Structure](https://learn.microsoft.com/windows/desktop/api/rtscom/ns-rtscom-stylusinfo) containing the information about the RTS that is associated with the stylus.

## Return value

For a description of return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

The stylus button is no longer down and the stylus is in range of the digitizer.

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::StylusButtonDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusbuttondown)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)