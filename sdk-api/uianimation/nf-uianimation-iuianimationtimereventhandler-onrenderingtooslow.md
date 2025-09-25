# IUIAnimationTimerEventHandler::OnRenderingTooSlow

## Description

Handles events that occur when the rendering frame rate
for an animation falls below a minimum desirable frame rate.

## Parameters

### `framesPerSecond` [in]

The current frame rate, in frames per second.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [UIAnimation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

The minimum desirable frame rate is specified using the [IUIAnimationTimer::SetFrameRateThreshold](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-setframeratethreshold) method.

## See also

[IUIAnimationTimer::SetFrameRateThreshold](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-setframeratethreshold)

[IUIAnimationTimer::SetTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtimer-settimereventhandler)

[IUIAnimationTimerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtimereventhandler)