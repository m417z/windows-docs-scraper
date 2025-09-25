# IUIAnimationStoryboard2::HoldVariable

## Description

Directs the storyboard to hold the specified animation variable at its final value until the storyboard ends.

## Parameters

### `variable` [in]

The animation variable.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

When a storyboard is playing, it has exclusive access to any variables it animates unless the storyboard is trimmed by a higher-priority storyboard. Typically, this exclusive access is released when the last transition in the storyboard for that variable finishes playing. Applications can call this method to maintain exclusive access to the animation variable and hold the variable, at the final value of the last transition, until the end of the storyboard.

## See also

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)