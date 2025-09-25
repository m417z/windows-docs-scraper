# IUIAnimationManager::SetTrimPriorityComparison

## Description

Sets the priority comparison handler to be called to determine whether a scheduled storyboard can be trimmed.

## Parameters

### `comparison` [in, optional]

The priority comparison handler for trimming.
The specified object must implement the [IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison) interface or be **NULL**.

See Remarks.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Setting a priority comparison handler with this method enables the application to indicate when scheduling conflicts can be resolved by trimming the scheduled storyboard.

A scheduled storyboard can be trimmed only if the priority comparison object registered with this method returns **S_OK**. If the new storyboard trims the scheduled storyboard, the scheduled storyboard can no longer affect a variable once the new storyboard begins to animate that variable.

Passing **NULL** for the *comparison* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManager::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcancelprioritycomparison)

[IUIAnimationManager::SetCompressPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcompressprioritycomparison)

[IUIAnimationManager::SetConcludePriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setconcludeprioritycomparison)

[IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison)