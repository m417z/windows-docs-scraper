# RegisterPointerInputTarget function

## Description

Allows the caller to register a target window to which all pointer input of the specified type is redirected.

## Parameters

### `hwnd` [in]

The window to register as a global redirection target.

Redirection can cause the foreground window to lose activation (focus). To avoid this, ensure the window is a message-only window or has the [WS_EX_NOACTIVATE](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles) style set.

### `pointerType` [in]

Type of pointer input to be redirected to the specified window. This is any valid and supported value from the [POINTER_INPUT_TYPE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) enumeration. Note that the generic **PT_POINTER** type and the **PT_MOUSE** type are not valid in this parameter.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application with the UI Access privilege can use this function to register its own window to receive all input of the specified pointer input type. Each desktop allows only one such global redirection target window for each pointer input type at any given time. The first window to successfully register remains in effect until the window is unregistered or destroyed, at which point the role is available to the next qualified caller.

While the registration is in effect, all input of the specified pointer type, whether from an input device or injected by an application, is redirected to the registered window. However, when the process that owns the registered window injects input of the specified pointer type, such injected is not redirected but is instead processed normally.

An application that wishes to register the same window as a global redirection target for multiple pointer input types must call the **RegisterPointerInputTarget** function multiple times, once for each pointer input type of interest.

If the calling thread does not have the UI Access privilege, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified pointer input type is not valid, this function fails with the last error set to **ERROR_INVALID_PARAMETER**.

If the calling thread does not own the specified window, this function fails with the last error set to **ERROR_ACCESS_DENIED**.

If the specified window’s desktop already has a registered global redirection target for the specified pointer input type, this function fails with the last error set to **ERROR_ACCESS_DENIED**.