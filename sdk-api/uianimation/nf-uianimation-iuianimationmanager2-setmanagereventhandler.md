# IUIAnimationManager2::SetManagerEventHandler

## Description

Specifies a handler for animation manager status updates.

## Parameters

### `handler` [in, optional]

The event handler to be called when the status of the animation manager changes.
The specified object must implement the [IUIAnimationManagerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler) interface or be **NULL**. See Remarks for more info.

### `fRegisterForNextAnimationEvent` [in]

If **TRUE**, specifies that [IUIAnimationManager2::EstimateNextEventTime](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-estimatenexteventtime) will incorporate *handler* into its estimate of the time interval until the next animation event. No default value.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing **NULL** for the *handler* parameter causes Windows Animation to release its reference to any handler object that you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager2::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-shutdown) method.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)

[IUIAnimationManagerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler)