# IDirectManipulationViewport::AddEventHandler

## Description

Adds a new event handler to listen for viewport events.

## Parameters

### `window` [in]

The handle of a window owned by the thread for the event callback.

### `eventHandler` [in]

The handler that is called when viewport status and update events occur. The specified object must implement the [IDirectManipulationViewportEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewporteventhandler) interface.

### `cookie` [out, retval]

The handle that represents this event handler callback.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event callback is fired from the thread that owns the specified window. Consecutive events of the same callback method may be coalesced.

**Note** If the viewport has a drag-drop behavior attached, the event handler should implement [IDirectManipulationDragDropEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdragdropeventhandler).

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)