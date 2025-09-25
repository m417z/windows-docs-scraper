# IDirectManipulationDragDropEventHandler::OnDragDropStatusChange

## Description

Called when a status change happens in the viewport that the drag-and-drop behavior is attached to.

## Parameters

### `viewport` [in]

The updated viewport.

### `current` [in]

The current state of the drag-drop interaction from [DIRECTMANIPULATION_DRAG_DROP_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_drag_drop_status).

### `previous` [in]

The previous state of the drag-drop interaction from [DIRECTMANIPULATION_DRAG_DROP_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_drag_drop_status).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If a class is implementing [IDirectManipulationViewportEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewporteventhandler) it should also implement [IDirectManipulationDragDropEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdragdropeventhandler) if that viewport will use drag and drop. [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) will query the **IDirectManipulationViewportEventHandler** instances to verify that they also implement **IDirectManipulationDragDropEventHandler**.

## See also

[IDirectManipulationDragDropEventHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdragdropeventhandler)