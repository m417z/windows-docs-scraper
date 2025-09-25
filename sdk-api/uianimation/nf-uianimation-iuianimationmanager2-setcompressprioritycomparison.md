# IUIAnimationManager2::SetCompressPriorityComparison

## Description

Sets the priority comparison handler that determines whether a scheduled storyboard can be compressed.

## Parameters

### `comparison` [in, optional]

The priority comparison handler for compression.
The specified object must implement the [IUIAnimationPriorityComparison2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison2) interface or be **NULL**. See Remarks for more info.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Setting a priority comparison handler with this method enables the application to indicate when scheduling conflicts can be resolved by compressing the scheduled storyboard and any other storyboards animating the same variables.

A storyboard can be compressed only if the priority comparison object registered with this method returns **S_OK** for all the other scheduled storyboards that will be affected by compression. When the storyboards are compressed, time is temporarily accelerated for affected storyboards, so they play faster.

Passing **NULL** for the *comparison* parameter causes Windows Animation to release its reference to any handler object that you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager2::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-shutdown) method.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[IUIAnimationManager2::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-setcancelprioritycomparison)

[IUIAnimationManager2::SetConcludePriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-setconcludeprioritycomparison)

[IUIAnimationManager2::SetTrimPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-settrimprioritycomparison)

[IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison)