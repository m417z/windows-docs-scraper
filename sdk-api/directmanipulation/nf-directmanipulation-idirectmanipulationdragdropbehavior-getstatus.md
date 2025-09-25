# IDirectManipulationDragDropBehavior::GetStatus

## Description

Gets the status of the drag-drop interaction for the viewport this behavior is attached to.

## Parameters

### `status` [out, retval]

One of the values from [DIRECTMANIPULATION_DRAG_DROP_STATUS](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_drag_drop_status).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the drag-drop status at the time of the call and not at the time when the return value is read.

## See also

[IDirectManipulationDragDropBehavior](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationdragdropbehavior)