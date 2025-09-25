# IUIAnimationTimer::SetFrameRateThreshold

## Description

Sets the frame rate below which the timer notifies the application that rendering is too slow.

## Parameters

### `framesPerSecond` [in]

The minimum desirable frame rate, in frames per second.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

If the rendering frame rate for an animation falls below the specified frame rate, an
[IUIAnimationTimerEventHandler::OnRenderingTooSlow](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimereventhandler-onrenderingtooslow) event is raised.

## See also

[IUIAnimationTimer](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimer)

[IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler)