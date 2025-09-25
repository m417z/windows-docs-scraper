# IRealTimeStylus::RemoveStylusAsyncPlugin

## Description

Removes and optionally returns an [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) with the specified index in the asynchronous plug-in collection.

## Parameters

### `iIndex` [in]

The index of the plug-in to be removed.

### `ppiPlugin` [in, out]

A pointer to the plug-in to remove. If you are not interested in receiving the pointer to the removed plug-in, pass **NULL** for this parameter.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## See also

[IRealTimeStylus](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-irealtimestylus)

[IRealTimeStylus::RemoveAllStylusAsyncPlugins Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-removeallstylusasyncplugins)

[IRealTimeStylus::RemoveStylusSyncPlugin Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-removestylussyncplugin)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)