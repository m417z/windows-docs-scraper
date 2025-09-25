# SwapMouseButton function

## Description

Reverses or restores the meaning of the left and right mouse buttons.

## Parameters

### `fSwap` [in]

Type: **BOOL**

If this parameter is **TRUE**, the left button generates right-button messages and the right button generates left-button messages. If this parameter is **FALSE**, the buttons are restored to their original meanings.

## Return value

Type: **BOOL**

If the meaning of the mouse buttons was reversed previously, before the function was called, the return value is nonzero.

If the meaning of the mouse buttons was not reversed, the return value is zero.

## Remarks

Button swapping is provided as a convenience to people who use the mouse with their left hands. The **SwapMouseButton** function is usually called by Control Panel only. Although an application is free to call the function, the mouse is a shared resource and reversing the meaning of its buttons affects all applications.

## See also

**Conceptual**

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**

[SetDoubleClickTime](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdoubleclicktime)