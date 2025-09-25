# HOOKPROC callback function

## Description

An application-defined or library-defined callback function used with the [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa) function. The system calls this function after the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function is called. The hook procedure can examine the message; it cannot modify it.

The **HOOKPROC** type defines a pointer to this callback function. *CallWndRetProc* is a placeholder for the application-defined or library-defined function name.

## Parameters

### `code`

### `wParam` [in]

Type: **WPARAM**

Specifies whether the message is sent by the current process. If the message is sent by the current process, it is nonzero; otherwise, it is **NULL**.

### `lParam` [in]

Type: **LPARAM**

A pointer to a [CWPRETSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-cwpretstruct) structure that contains details about the message.

#### - nCode [in]

Type: **int**

Specifies whether the hook procedure must process the message. If *nCode* is **HC_ACTION**, the hook procedure must process the message. If *nCode* is less than zero, the hook procedure must pass the message to the [CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) function without further processing and should return the value returned by **CallNextHookEx**.

## Return value

Type: **LRESULT**

If *nCode* is less than zero, the hook procedure must return the value returned by [CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex).

If *nCode* is greater than or equal to zero, it is highly recommended that you call [CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) and return the value it returns; otherwise, other applications that have installed [WH_CALLWNDPROCRET](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks) hooks will not receive hook notifications and may behave incorrectly as a result. If the hook procedure does not call **CallNextHookEx**, the return value should be zero.

## Remarks

An application installs the hook procedure by specifying the [WH_CALLWNDPROCRET](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks) hook type and a pointer to the hook procedure in a call to the [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa) function.

## See also

[CWPRETSTRUCT structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-cwpretstruct), [CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex), [CallWindowProcW function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowprocw), [CallWindowProcA function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowproca), [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage), [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa), [Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)