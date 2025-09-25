# IUIAnimationManager::SetCompressPriorityComparison

## Description

Sets the priority comparison handler to be called to determine whether a scheduled storyboard can be compressed.

## Parameters

### `comparison` [in, optional]

The priority comparison handler for compression.
The specified object must implement the [IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison) interface or be **NULL**. See Remarks.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Setting a priority comparison handler with this method enables the application to indicate when the scheduling conflicts can be resolved by compressing the scheduled storyboard and any other storyboards animating the same variables.

A storyboard can be compressed only if the priority comparison object registered with this method returns **S_OK** for all the other scheduled storyboards that will be affected by compression. When the storyboards are compressed, time is temporarily accelerated for affected storyboards, so they play faster.

Passing **NULL** for the *comparison* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManager::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcancelprioritycomparison)

[IUIAnimationManager::SetConcludePriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setconcludeprioritycomparison)

[IUIAnimationManager::SetTrimPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-settrimprioritycomparison)

[IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison)