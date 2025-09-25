# IUIAnimationVariable::GetCurrentStoryboard

## Description

Gets the storyboard that is currently animating the animation variable.

## Parameters

### `storyboard` [out]

The current storyboard, or **NULL** if no storyboard is currently animating the animation variable.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [UIAnimation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)