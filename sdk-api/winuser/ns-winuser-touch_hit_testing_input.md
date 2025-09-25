# TOUCH_HIT_TESTING_INPUT structure

## Description

Contains information about the touch contact area reported by the touch digitizer.

## Members

### `pointerId`

The ID of the pointer. You cannot pass this value to the input message process and retrieve additional pointer info through [GetPointerInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpointerinfo).

### `point`

The screen coordinates of the touch point that the touch digitizer reports.

### `boundingBox`

The bounding rectangle of the touch contact area. Valid touch targets are identified and scored based on this bounding box.

**Note** This bounding box may differ from the contact area that the digitizer reports when:

* The digitizer reports a touch contact area that's outside the maximum or minimum size threshold that's recognized by [Touch Hit Testing](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/touch-hit-testing-portal).
* A portion of the touch contact area is occluded by another object that's higher in the z-order.

### `nonOccludedBoundingBox`

The touch contact area within a specific targeted window that's not occluded by other objects that are higher in the z-order. Any area that's occluded by another object is an invalid target.

### `orientation`

The orientation of the touch contact area.

## See also

[Structures](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/structures)