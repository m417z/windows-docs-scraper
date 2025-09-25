# IUIAnimationManager2::Shutdown

## Description

Shuts down the animation manager and all its associated objects.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Calling this method directs the animation manager, and all the objects it created, to
release all their pointers to other objects. After **IUIAnimationManager2::Shutdown** has been called, no other methods may be called on the animation manager or on any objects that it created. An application can call this method to clean up if there is any possibility that the application has introduced a reference cycle that includes some animation objects.

## See also

[IUIAnimationManager2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager2)