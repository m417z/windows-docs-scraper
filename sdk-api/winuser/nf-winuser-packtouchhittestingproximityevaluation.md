# PackTouchHitTestingProximityEvaluation function

## Description

Returns the proximity evaluation score and the adjusted touch-point coordinates as a packed value for the [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) callback.

## Parameters

### `pHitTestingInput` [in]

The [TOUCH_HIT_TESTING_INPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touch_hit_testing_input) structure that holds the data for the touch contact area.

### `pProximityEval` [in]

The [TOUCH_HIT_TESTING_PROXIMITY_EVALUATION](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-touch_hit_testing_proximity_evaluation) structure that holds the score and adjusted touch-point data that the [EvaluateProximityToPolygon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-evaluateproximitytopolygon) or [EvaluateProximityToRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-evaluateproximitytorect) function returns.

## Return value

If this function succeeds, it returns the **score** and **adjustedPoint** values from [TOUCH_HIT_TESTING_PROXIMITY_EVALUATION](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-touch_hit_testing_proximity_evaluation) as an LRESULT. To retrieve extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Usually, this is the last function that's called in a [WM_TOUCHHITTESTING](https://learn.microsoft.com/windows/win32/inputmsg/wm-touchhittesting) handler.

## See also

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/functions)

[Touch Hit Testing Scores](https://learn.microsoft.com/previous-versions/windows/desktop/input_touchhittest/hit-testing-scores)