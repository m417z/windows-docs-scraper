# DebugProc function

An application-defined or library-defined callback function used with the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function. The system calls this function before calling the hook procedures associated with any type of hook. The system passes information about the hook to be called to the *DebugProc* hook procedure, which examines the information and determines whether to allow the hook to be called.

The **HOOKPROC** type defines a pointer to this callback function. *DebugProc* is a placeholder for the application-defined or library-defined function name.

## Parameters

  - *nCode* \[in\]
Type: **int**
Specifies whether the hook procedure must process the message. If *nCode* is HC\_ACTION, the hook procedure must process the message. If *nCode* is less than zero, the hook procedure must pass the message to the [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) function without further processing and should return the value returned by **CallNextHookEx**.

  - *wParam* \[in\]
Type: **WPARAM**
The type of hook about to be called. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WH_CALLWNDPROC** 4 | Installs a hook procedure that monitors messages sent to a window procedure. For more information, see the description of the [*CallWndProc*](https://learn.microsoft.com/windows/win32/winmsg/callwndproc) hook procedure. |
| **WH_CALLWNDPROCRET** 12 | Installs a hook procedure that monitors messages that have just been processed by a window procedure. For more information, see the description of the [*CallWndRetProc*](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-hookproc) hook procedure. |
| **WH_CBT** 5 | Installs a hook procedure that receives notifications useful to a CBT application. For more information, see the description of the [**CBTProc**](https://learn.microsoft.com/windows/win32/winmsg/cbtproc) hook procedure. |
| **WH_DEBUG** 9 | Installs a hook procedure useful for debugging other hook procedures. For more information, see the description of the *DebugProc* hook procedure. |
| **WH_GETMESSAGE** 3 | Installs a hook procedure that monitors messages posted to a message queue. For more information, see the description of the[*GetMsgProc*](https://learn.microsoft.com/windows/win32/winmsg/getmsgproc) hook procedure. |
| **WH_JOURNALPLAYBACK** 1 | Installs a hook procedure that posts messages previously recorded by a **WH_JOURNALRECORD** hook procedure. For more information, see the description of the [*JournalPlaybackProc*](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc) hook procedure. |
| **WH_JOURNALRECORD** 0 | Installs a hook procedure that records input messages posted to the system message queue. This hook is useful for recording macros. For more information, see the description of the [*JournalRecordProc*](https://learn.microsoft.com/windows/win32/winmsg/journalrecordproc) hook procedure. |
| **WH_KEYBOARD** 2 | Installs a hook procedure that monitors keystroke messages. For more information, see the description of the [*KeyboardProc*](https://learn.microsoft.com/windows/win32/winmsg/keyboardproc) hook procedure. |
| **WH_MOUSE** 7 | Installs a hook procedure that monitors mouse messages. For more information, see the description of the [*MouseProc*](https://learn.microsoft.com/windows/win32/winmsg/mouseproc) hook procedure. |
| **WH_MSGFILTER**     -1 | Installs a hook procedure that monitors messages generated as a result of an input event in a dialog box, message box, menu, or scroll bar. The hook procedure monitors these messages only for the application that installed the hook procedure. For more information, see the [*MessageProc*](https://learn.microsoft.com/windows/win32/winmsg/messageproc) hook procedure. |
| **WH_SHELL** 10 | Installs a hook procedure that receives notifications useful to a Shell application. For more information, see the description of the [*ShellProc*](https://learn.microsoft.com/windows/win32/winmsg/shellproc) hook procedure and the [**WH_SHELL**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook section. |
| **WH_SYSMSGFILTER** 6 | Installs a hook procedure that monitors messages generated as a result of an input event in a dialog box, message box, menu, or scroll bar. The hook procedure monitors these messages for all applications in the system. For more information, see the description of the [*SysMsgProc*](https://learn.microsoft.com/windows/win32/winmsg/sysmsgproc) hook procedure. |

  - *lParam* \[in\]
Type: **LPARAM**
A pointer to a [**DEBUGHOOKINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-debughookinfo) structure that contains the parameters to be passed to the destination hook procedure.

## Return value

Type: ****

Type: LRESULT

To prevent the system from calling the hook, the hook procedure must return a nonzero value. Otherwise, the hook procedure must call [**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex).

## Remarks

An application installs this hook procedure by specifying the [**WH_DEBUG**](https://learn.microsoft.com/windows/win32/winmsg/about-hooks) hook type and the pointer to the hook procedure in a call to the [**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw) function.

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 2000 Professional [desktop apps only] |
| Minimum supported server | Windows 2000 Server [desktop apps only] |
| Header | Winuser.h (include Windows.h) |

## See also

[**CallNextHookEx**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex)

[*CallWndProc*](https://learn.microsoft.com/windows/win32/winmsg/callwndproc)

[*CallWndRetProc*](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-hookproc)

[*CBTProc*](https://learn.microsoft.com/windows/win32/winmsg/cbtproc)

[**DEBUGHOOKINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-debughookinfo)

[*GetMsgProc*](https://learn.microsoft.com/windows/win32/winmsg/getmsgproc)

[*JournalPlaybackProc*](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc)

[*JournalRecordProc*](https://learn.microsoft.com/windows/win32/winmsg/journalrecordproc)

[*KeyboardProc*](https://learn.microsoft.com/windows/win32/winmsg/keyboardproc)

[*MessageProc*](https://learn.microsoft.com/windows/win32/winmsg/messageproc)

[*MouseProc*](https://learn.microsoft.com/windows/win32/winmsg/mouseproc)

[**SetWindowsHookExA**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexa)/[**SetWindowsHookExW**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setwindowshookexw)

[*ShellProc*](https://learn.microsoft.com/windows/win32/winmsg/shellproc)

[*SysMsgProc*](https://learn.microsoft.com/windows/win32/winmsg/sysmsgproc)

[Hooks](https://learn.microsoft.com/windows/win32/winmsg/hooks)