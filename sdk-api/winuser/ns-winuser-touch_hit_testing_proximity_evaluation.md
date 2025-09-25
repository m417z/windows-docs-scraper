# TOUCH_HIT_TESTING_PROXIMITY_EVALUATION structure

## Description

Contains the hit test score that indicates whether the object is the likely target of the touch contact area, relative to other objects that intersect the touch contact area.

## Members

### `score`

The score, compared to the other objects that intersect the touch contact area.

### `adjustedPoint`

The adjusted touch point that hits the closest object that's identified by the value of *Score*.

## Remarks

The [EvaluateProximityToRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-evaluateproximitytorect) or [EvaluateProximityToPolygon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-evaluateproximitytopolygon) function returns the values.

## See also

[Structures](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/structures)