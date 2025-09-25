# IPointerInactive::OnInactiveMouseMove

## Description

Notifies the object that the mouse pointer has moved over it so the object can fire mouse events. This method is called by the container on receipt of a WM_MOUSEMOVE method when an inactive object is under the mouse pointer.

## Parameters

### `pRectBounds` [in]

The object bounding rectangle, in client coordinates of the containing window. This parameter tells the object its exact position and size on the screen when the WM_MOUSEMOVE message was received. This value is specified in units of the client's coordinate system.

### `x` [in]

The horizontal coordinate of mouse location in units of the client's containing window.

### `y` [in]

The vertical coordinate of mouse location in units of the client's containing window.

### `grfKeyState` [in]

The current state of the keyboard modifier keys on the keyboard. Possible values can be a combination of any of the values MK_CONTROL, MK_SHIFT, MK_ALT, MK_BUTTON, MK_LBUTTON, MK_MBUTTON, and MK_RBUTTON.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The container calls this method to notify the object that the mouse pointer is over the object after checking the object's activation policy by calling the [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method. If the object has not requested to be activated in-place through that call, the container dispatches subsequent WM_MOUSEMOVE messages to the inactive object by calling **OnInactiveMouseMove** as long as the mouse pointer stays over the object. The object can then fire mouse move events.

To avoid rounding errors and to make the job easier on the object implementer, this method takes window coordinates in the units of its containing client window, that is, the window in which the object is displayed, instead of the usual **HIMETRIC** units. Thus, the same coordinates and code path can be used when the object is active and inactive. The window coordinates specify the mouse position. The bounding rectangle is also specified in the same coordinate system.

## See also

[IPointerInactive](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive)