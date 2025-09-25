# IUIAnimationManager::SetManagerEventHandler

## Description

Specifies a handler for animation manager status updates.

## Parameters

### `handler` [in, optional]

The event handler to be called when the status of the animation manager changes.
The specified object must implement the [IUIAnimationManagerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler) interface or be **NULL**.

See Remarks section for more information.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing **NULL** for the *handler* parameter causes Windows Animation to release its reference to any handler object that you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

#### Examples

For an example, see [Update the Animation Manager and Draw Frames](https://learn.microsoft.com/windows/desktop/UIAnimation/introducing-windows-animation-manager).

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationManagerEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanagereventhandler)