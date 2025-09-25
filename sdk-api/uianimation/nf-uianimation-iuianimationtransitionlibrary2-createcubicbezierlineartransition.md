# IUIAnimationTransitionLibrary2::CreateCubicBezierLinearTransition

## Description

Creates a cubic Bézier linear scalar transition.

## Parameters

### `duration` [in]

The duration of the transition.

### `finalValue` [in]

The value of the animation variable at the end of the transition.

### `x1` [in]

The x-coordinate of the first control point.

### `y1` [in]

The y-coordinate of the first control point.

### `x2` [in]

The x-coordinate of the second control point.

### `y2` [in]

The y-coordinate of the second control point.

### `ppTransition` [out]

The new cubic Bézier linear transition.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

During a cubic Bézier linear transition, the value of the animation variable changes from its initial value to the *finalValue* over the *duration* of the transition. The ordered pairs, (x1, y1) and (x2, y2), act as control points that provide directional information to transform the linear path of the transition into a smooth parametric curve.

The following figure shows the change in value over time for an animation variable during a cubic Bézier linear transition.

![Diagram showing a cubic Bezier linear transition](https://learn.microsoft.com/windows/win32/api/uianimation/Images/cubicbezierlineartransition.png)

## See also

[IUIAnimationTransition2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition2)

[IUIAnimationTransitionLibrary2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransitionlibrary2)