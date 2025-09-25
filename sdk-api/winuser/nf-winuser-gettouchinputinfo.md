# GetTouchInputInfo function

## Description

Retrieves detailed information about touch inputs associated with a particular touch input handle.

## Parameters

### `hTouchInput` [in]

The touch input handle received in the **LPARAM** of a touch message. The function fails with **ERROR_INVALID_HANDLE** if this handle is not valid. Note that the handle is not valid after it has been used in a successful call to [CloseTouchInputHandle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closetouchinputhandle) or after it has been passed to [DefWindowProc, PostMessage, SendMessage](https://learn.microsoft.com/windows/desktop/wintouch/sendmessage--postmessage--and-related-functions) or one of their variants.

### `cInputs` [in]

The number of structures in the *pInputs* array. This should ideally be at least equal to the number of touch points associated with the message as indicated in the message **WPARAM**. If *cInputs* is less than the number of touch points, the function will still succeed and populate the *pInputs* buffer with information about *cInputs* touch points.

### `pInputs` [out]

A pointer to an array of [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structures to receive information about the touch points associated with the specified touch input handle.

### `cbSize` [in]

The size, in bytes, of a single [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure. If *cbSize* is not the size of a single **TOUCHINPUT** structure, the function fails with **ERROR_INVALID_PARAMETER**.

## Return value

If the function succeeds, the return value is nonzero.
If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Calling [CloseTouchInputHandle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closetouchinputhandle) will not free memory associated with values retrieved in a call to **GetTouchInputInfo**. Values in structures passed to **GetTouchInputInfo** will be valid until you delete them.

## See also

[CloseTouchInputHandle](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closetouchinputhandle)

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtfunctions)

[TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput)