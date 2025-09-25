# EvaluateProximityToRect function

## Description

Returns the score of a rectangle as the probable touch target, compared to all other rectangles that intersect the touch contact area, and an adjusted touch point within the rectangle.

## Parameters

### `controlBoundingBox` [in]

The [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the bounding box of the UI element.

### `pHitTestingInput` [in]

The [TOUCH_HIT_TESTING_INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touch_hit_testing_input) structure that holds the data for the touch contact area.

### `pProximityEval` [out]

The [TOUCH_HIT_TESTING_PROXIMITY_EVALUATION](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-touch_hit_testing_proximity_evaluation) structure that holds the score and adjusted touch-point data.

## Return value

If this function succeeds, it returns TRUE.
Otherwise, it returns FALSE. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

For consistency with Windows, frameworks that handle [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) should use the following principles for targeting:

* Inclusion: If the touch point is within the boundaries of a control, the touch point is not changed.
* Intersection: Include only controls that intersect the contact geometry.
* Z-order: If more than one control intersects the contact geometry, and the controls overlap, the control that's highest in the z-order receives priority.
* Ambiguity: If more than one control intersects the contact geometry, and the controls don't overlap, the control that's closest to the original touch point receives priority.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/functions)