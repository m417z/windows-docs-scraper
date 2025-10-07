# ForegroundIdleProc callback function

An application-defined or library-defined callback function used with the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function. The system calls this function whenever the foreground thread is about to become idle.

## Parameters

  - *code* \[in\]
Type: **int**
If *code* is **HC\_ACTION**, the hook procedure must process the message. If *code* is less than zero, the hook procedure must pass the message to the [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) function without further processing and should return the value returned by **CallNextHookEx**.

  - *wParam*
Type: **DWORD**
This parameter is not used.

  - *lParam*
Type: **LONG**
This parameter is not used.

## Return value

Type: ****

Type: DWORD

If *code* is less than zero, the hook procedure must return the value returned by [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex).

If *code* is greater than or equal to zero, it is highly recommended that you call [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) and return the value it returns; otherwise, other applications that have installed [**WH_FOREGROUNDIDLE**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hooks will not receive hook notifications and may behave incorrectly as a result. If the hook procedure does not call **CallNextHookEx**, the return value should be zero.

## Remarks

The **HOOKPROC** type defines a pointer to this callback function. *ForegroundIdleProc* is a placeholder for the application-defined or library-defined function name.

An application installs this hook procedure by specifying the [**WH_FOREGROUNDIDLE**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook type and the pointer to the hook procedure in a call to the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function.

While processing this callback function, avoid calling any functions that retrieve window messages from the calling thread's message queue. This includes [**GetMessage**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getmessage), [**PeekMessageA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-peekmessagea)/[**PeekMessageW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-peekmessagew), modal dialog box, and COM functions. Calling such functions may result in the thread not returning from **GetMessage** or [**WaitMessage**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-waitmessage) when there are messages in the calling thread's message queue.

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 2000 Professional [desktop apps only] |
| Minimum supported server | Windows 2000 Server [desktop apps only] |
| Header | Winuser.h (include Windows.h) |

## See also

**Reference**

[**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex)

[**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw)

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/win32/winmsg/hooks)