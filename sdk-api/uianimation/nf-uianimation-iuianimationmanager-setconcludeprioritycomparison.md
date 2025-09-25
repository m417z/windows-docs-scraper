# IUIAnimationManager::SetConcludePriorityComparison

## Description

Sets the priority comparison handler to be called to determine whether a scheduled storyboard can be concluded.

## Parameters

### `comparison` [in, optional]

The priority comparison handler for conclusion. The specified object must implement the [IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison) interface or be **NULL**.
See Remarks.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Setting a priority comparison handler with this method enables the application to indicate when scheduling conflicts can be resolved by concluding the scheduled storyboard.

A scheduled storyboard can be concluded only if it contains a loop with a repetition count of [UI_ANIMATION_REPEAT_INDEFINITELY](https://learn.microsoft.com/windows/desktop/UIAnimation/ui-animation-repeat-indefinitely) and the priority comparison object registered with this method returns **S_OK**. If the storyboard is concluded, the current repetition of the loop completes, and the reminder of the storyboard then plays.

Passing **NULL** for the *comparison* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManager::SetCancelPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcancelprioritycomparison)

[IUIAnimationManager::SetCompressPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-setcompressprioritycomparison)

[IUIAnimationManager::SetTrimPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-settrimprioritycomparison)

[IUIAnimationPriorityComparison](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationprioritycomparison)