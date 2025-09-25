# IUIAnimationManagerEventHandler2::OnManagerStatusChanged

## Description

Handles status changes to an [animation manager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2).

## Parameters

### `newStatus` [in]

The new status of the animation manager.

### `previousStatus` [in]

The previous status of the animation manager.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calls made to other Windows Animation methods from **IUIAnimationManager2::OnManagerStatusChanged** fail and return **UI_E_ILLEGAL_REENTRANCY**.

## See also

[IUIAnimationManager2::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstatus)

[IUIAnimationManagerEventHandler2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler2)

[UI_ANIMATION_MANAGER_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_manager_status)