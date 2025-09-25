# IUIAnimationManagerEventHandler::OnManagerStatusChanged

## Description

Handles status changes to an animation manager.

## Parameters

### `newStatus` [in]

The new status.

### `previousStatus` [in]

The previous status.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A call made in this callback method to any other animation method results in the call failing and returning **UI_E_ILLEGAL_REENTRANCY**.

## See also

[IUIAnimationManager::GetStatus](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstatus)

[IUIAnimationManagerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler)

[UI_ANIMATION_MANAGER_STATUS](https://learn.microsoft.com/windows/win32/api/uianimation/ne-uianimation-ui_animation_manager_status)