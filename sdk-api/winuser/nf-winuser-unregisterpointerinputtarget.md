# UnregisterPointerInputTarget function

## Description

Allows the caller to unregister a target window to which all pointer input of the specified type is redirected.

## Parameters

### `hwnd` [in]

Window to be un-registered as a global redirection target on its desktop.

### `pointerType` [in]

Type of pointer input to no longer be redirected to the specified window. This is any valid and supported value from the [POINTER_INPUT_TYPE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)  enumeration. Note that the generic **PT_POINTER** type and the **PT_MOUSE** type are not valid in this parameter.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application that has successfully called the [RegisterPointerInputTarget](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerpointerinputtarget) function can call this function to un-register the window from the role of global redirected target for the specified pointer type.

An application that has registered the same window as a global redirection target for multiple pointer input types can call the **UnregisterPointerInputTarget** to un-register the window for one of those types while leaving the window registered for the remaining types.

If the calling thread does not have the UI Access privilege, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified pointer input type is not valid, this function fails with the last error set to **ERROR_INVALID_PARAMETER**.

If the calling thread does not own the specified window, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified window is not the registered global redirection target for the specified pointer input type on its desktop, this function takes no action and returns success.