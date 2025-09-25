# IPointerInactive::OnInactiveSetCursor

## Description

Sets the mouse pointer for an inactive object. This method is called by the container on receipt of a WM_SETCURSOR method when an inactive object is under the mouse pointer.

## Parameters

### `pRectBounds` [in]

The object bounding rectangle specified in client coordinate units of the containing window. This parameter tells the object its exact position and size on the screen when the WM_SETCURSOR message was received. This value is specified in units of the client's coordinate system.

### `x` [in]

The horizontal coordinate of mouse location in units of the client's containing window.

### `y` [in]

The vertical coordinate of mouse location in units of the client's containing window.

### `dwMouseMsg` [in]

The identifier of the mouse message for which a WM_SETCURSOR occurred.

### `fSetAlways` [in]

If this value is **TRUE**, the object must set the cursor; if this value is **FALSE**, the object is not obligated to set the cursor, and should return S_FALSE in that case.

## Return value

This method can return the standard return value E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The mouse pointer was successfully set. |
| **S_FALSE** | The object did not set the cursor; the container should either set the cursor or call the object again with the parameter *fSetAlways* set to **TRUE**. |

## Remarks

The container calls this method to set the mouse pointer over an inactive object after checking the object's activation policy by calling the [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method. If the object has not requested to be activated in-place through that call, the container dispatches subsequent WM_SETCURSOR messages to the inactive object by calling **OnInactiveSetCursor** as long as the mouse pointer stays over the object.

To avoid rounding errors and to make the job easier on the object implementer, this method takes window coordinates in the units of its containing client window, that is, the window in which the object is displayed, instead of the usual **HIMETRIC** units. Thus, the same coordinates and code path can be used when the object is active and inactive. The window coordinates specify the mouse position. The bounding rectangle is also specified in the same coordinate system.

**OnInactiveSetCursor** takes an additional parameter, *fSetAlways*, that indicates whether the object is obligated to set the cursor or not. Containers should first call this method with this parameter **FALSE**. The object may return S_FALSE to indicate that it did not set the cursor. In that case, the container should either set the cursor itself, or, if it does not wish to do this, call the **OnInactiveSetCursor** method again with *fSetAlways* being **TRUE**.

## See also

[IPointerInactive](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive)