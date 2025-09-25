# DIRECTMANIPULATION_DRAG_DROP_STATUS enumeration

## Description

Defines the drag-and-drop interaction states for the viewport.

## Constants

### `DIRECTMANIPULATION_DRAG_DROP_READY:0`

The viewport is at rest and ready for input.

### `DIRECTMANIPULATION_DRAG_DROP_PRESELECT:1`

The viewport is updating its content and the content is not selected.

### `DIRECTMANIPULATION_DRAG_DROP_SELECTING:2`

The viewport is updating its content and the content is selected.

### `DIRECTMANIPULATION_DRAG_DROP_DRAGGING:3`

The viewport is updating its content and the content is being dragged.

### `DIRECTMANIPULATION_DRAG_DROP_CANCELLED:4`

The viewport has concluded the interaction and requests a revert.

### `DIRECTMANIPULATION_DRAG_DROP_COMMITTED:5`

The viewport has concluded the interaction and requests a commit.

## Remarks

For each interaction, the status always starts at **DIRECTMANIPULATION_DRAG_DROP_READY** and ends at either **DIRECTMANIPULATION_DRAG_DROP_CANCELLED** or **DIRECTMANIPULATION_DRAG_DROP_COMMITTED**. There are no explicit callbacks for the transition from CANCELLED/COMMITTED to READY.

The meaning of the CANCELLED and COMMITTED values depend on the previous status.

* For **DIRECTMANIPULATION_DRAG_DROP_PRESELECT**, they mean the same thing: the content goes back to the original location and no other actions should be taken.
* FOR **DIRECTMANIPULATION_DRAG_DROP_SELECTING**, COMMITTED means apply the selection change; CANCELLED means avoid the selection change.
* For **DIRECTMANIPULATION_DRAG_DROP_DRAGGING**, COMMITTED means perform the drop action; CANCELLED means cancel the drop action.

## See also

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)