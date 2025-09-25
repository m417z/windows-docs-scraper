# IUIAnimationLoopIterationChangeHandler2::OnLoopIterationChanged

## Description

Handles loop iteration change events, which occur when a loop within a storyboard begins a new iteration.

## Parameters

### `storyboard` [in]

The storyboard to which the loop belongs.

### `id` [in]

The loop ID.

### `newIterationCount` [in]

The iteration count for the latest [IUIAnimationManager2::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-update).

### `oldIterationCount` [in]

The iteration count for the previous [IUIAnimationManager2::Update](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-update).

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## See also

[IUIAnimationLoopIterationChangeHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationloopiterationchangehandler2)