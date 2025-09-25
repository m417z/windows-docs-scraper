# CloseTouchInputHandle function

## Description

Closes a touch input handle, frees process memory associated with it, and invalidates the handle.

## Parameters

### `hTouchInput` [in]

The touch input handle received in the **LPARAM** of a touch message. The function fails with **ERROR_INVALID_HANDLE** if this handle is not valid. Note that the handle is not valid after it has been used in a successful call to **CloseTouchInputHandle** or after it has been passed to [DefWindowProc, PostMessage, SendMessage](https://learn.microsoft.com/windows/desktop/wintouch/sendmessage--postmessage--and-related-functions) or one of their variants.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Calling **CloseTouchInputHandle** will not free memory associated with values retrieved in a call to [GetTouchInputInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-gettouchinputinfo). Values in structures passed to **GetTouchInputInfo** will be valid until you delete them.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wintouch/mtfunctions)

[GetTouchInputInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-gettouchinputinfo)