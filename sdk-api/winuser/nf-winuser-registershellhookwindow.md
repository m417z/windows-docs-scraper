# RegisterShellHookWindow function

## Description

[This function is not intended for general
use. It may
be altered or unavailable in subsequent versions of Windows.]

Registers a specified Shell window to receive certain messages for events or notifications that are useful to Shell applications.

The event messages received are only those sent to the Shell window associated with the specified window's desktop. Many of the messages are the same as those that can be received after calling the [SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa) function and specifying **WH_SHELL** for the hook type. The difference with **RegisterShellHookWindow** is that the messages are received through the specified window's [WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc) and not through a call back procedure.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window to register for Shell hook messages.

## Return value

Type: **BOOL**

**TRUE** if the function succeeds; otherwise, **FALSE**.

## Remarks

As with normal window messages, the second parameter of the window procedure identifies the message as a **WM_SHELLHOOKMESSAGE**. However, for these Shell hook messages, the message value is not a pre-defined constant like other message IDs such as [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command). The value must be obtained dynamically using a call to [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) as shown here:

`RegisterWindowMessage(TEXT("SHELLHOOK"));`

This precludes handling these messages using a traditional switch statement which requires ID values that are known at compile time. For handling Shell hook messages, the normal practice is to code an If statement in the default section of your switch statement and then handle the message if the value of the message ID is the same as the value
obtained from the [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) call.

The following table describes the *wParam* and *lParam* parameter values passed to the window procedure for the Shell hook messages.

| wParam | lParam |
| --- | --- |
| **HSHELL_GETMINRECT** | A pointer to a **SHELLHOOKINFO** structure. |
| **HSHELL_WINDOWACTIVATED** | A handle to the activated window. |
| **HSHELL_RUDEAPPACTIVATED** | A handle to the activated window. |
| **HSHELL_WINDOWREPLACING** | A handle to the window replacing the top-level window. |
| **HSHELL_WINDOWREPLACED** | A handle to the window being replaced. |
| **HSHELL_WINDOWCREATED** | A handle to the window being created. |
| **HSHELL_WINDOWDESTROYED** | A handle to the top-level window being destroyed. |
| **HSHELL_ACTIVATESHELLWINDOW** | Not used. |
| **HSHELL_TASKMAN** | Can be ignored. |
| **HSHELL_REDRAW** | A handle to the window that needs to be redrawn. |
| **HSHELL_FLASH** | A handle to the window that needs to be flashed. |
| **HSHELL_ENDTASK** | A handle to the window that should be forced to exit. |
| **HSHELL_APPCOMMAND** | The APPCOMMAND which has been unhandled by the application or other hooks. See [WM_APPCOMMAND](https://learn.microsoft.com/windows/desktop/inputdev/wm-appcommand) and use the [GET_APPCOMMAND_LPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-get_appcommand_lparam) macro to retrieve this parameter. |
| **HSHELL_MONITORCHANGED** | A handle to the window that moved to a different monitor. |

This function was not included in the SDK headers and libraries until Windows XP with Service Pack 1 (SP1) and Windows Server 2003. If you do not have a header file and import library for this function, you can call the function using [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).

## See also

**Conceptual**

[DeregisterShellHookWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-deregistershellhookwindow)

**Other Resources**

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

[ShellProc](https://learn.microsoft.com/windows/win32/winmsg/shellproc)

[Using Messages and Message Queues](https://learn.microsoft.com/windows/desktop/winmsg/using-messages-and-message-queues)

[WinEvents](https://learn.microsoft.com/windows/desktop/WinAuto/winevents-infrastructure)

[WindowProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-wndproc)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)