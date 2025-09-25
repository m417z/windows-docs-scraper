# SetWindowsHookExA function

## Description

Installs an application-defined hook procedure into a hook chain. You would install a hook procedure to monitor the system for certain types of events. These events are associated either with a specific thread or with all threads in the same desktop as the calling thread.

## Parameters

### `idHook` [in]

Type: **int**

The type of hook procedure to be installed. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WH_CALLWNDPROC**<br><br>4 | Installs a hook procedure that monitors messages before the system sends them to the destination window procedure. For more information, see the [CallWndProc](https://learn.microsoft.com/windows/win32/winmsg/callwndproc) hook procedure. |
| **WH_CALLWNDPROCRET**<br><br>12 | Installs a hook procedure that monitors messages after they have been processed by the destination window procedure. For more information, see the [HOOKPROC callback function](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-hookproc) hook procedure. |
| **WH_CBT**<br><br>5 | Installs a hook procedure that receives notifications useful to a CBT application. For more information, see the [CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc) hook procedure. |
| **WH_DEBUG**<br><br>9 | Installs a hook procedure useful for debugging other hook procedures. For more information, see the [*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc) hook procedure. |
| **WH_FOREGROUNDIDLE**<br><br>11 | Installs a hook procedure that will be called when the application's foreground thread is about to become idle. This hook is useful for performing low priority tasks during idle time. For more information, see the [*ForegroundIdleProc*](https://learn.microsoft.com/windows/win32/winmsg/foregroundidleproc) hook procedure. |
| **WH_GETMESSAGE**<br><br>3 | Installs a hook procedure that monitors messages posted to a message queue. For more information, see the [*GetMsgProc*](https://learn.microsoft.com/windows/win32/winmsg/getmsgproc) hook procedure. |
| **WH_JOURNALPLAYBACK**<br><br>1 | > [!WARNING] > **Windows 11 and newer**: Journaling hook APIs are not supported. We recommend using the [**SendInput**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-sendinput) TextInput API instead.<br><br>Installs a hook procedure that posts messages previously recorded by a [WH_JOURNALRECORD](https://learn.microsoft.com/windows/desktop/winmsg/about-hooks) hook procedure. For more information, see the [JournalPlaybackProc](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc) hook procedure. |
| **WH_JOURNALRECORD**<br><br>0 | > [!WARNING] > **Windows 11 and newer**: Journaling hook APIs are not supported. We recommend using the [**SendInput**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-sendinput) TextInput API instead.<br><br>Installs a hook procedure that records input messages posted to the system message queue. This hook is useful for recording macros. For more information, see the [JournalRecordProc](https://learn.microsoft.com/windows/win32/winmsg/journalrecordproc) hook procedure. |
| **WH_KEYBOARD**<br><br>2 | Installs a hook procedure that monitors keystroke messages. For more information, see the [KeyboardProc](https://learn.microsoft.com/windows/win32/winmsg/keyboardproc) hook procedure. |
| **WH_KEYBOARD_LL**<br><br>13 | Installs a hook procedure that monitors low-level keyboard input events. For more information, see the [LowLevelKeyboardProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelkeyboardproc) hook procedure. |
| **WH_MOUSE**<br><br>7 | Installs a hook procedure that monitors mouse messages. For more information, see the [MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc) hook procedure. |
| **WH_MOUSE_LL**<br><br>14 | Installs a hook procedure that monitors low-level mouse input events. For more information, see the [LowLevelMouseProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelmouseproc) hook procedure. |
| **WH_MSGFILTER**<br><br>-1 | Installs a hook procedure that monitors messages generated as a result of an input event in a dialog box, message box, menu, or scroll bar. For more information, see the [MessageProc](https://learn.microsoft.com/windows/win32/winmsg/messageproc) hook procedure. |
| **WH_SHELL**<br><br>10 | Installs a hook procedure that receives notifications useful to shell applications. For more information, see the [ShellProc](https://learn.microsoft.com/windows/win32/winmsg/shellproc) hook procedure. |
| **WH_SYSMSGFILTER**<br><br>6 | Installs a hook procedure that monitors messages generated as a result of an input event in a dialog box, message box, menu, or scroll bar. The hook procedure monitors these messages for all applications in the same desktop as the calling thread. For more information, see the [SysMsgProc](https://learn.microsoft.com/windows/win32/winmsg/sysmsgproc) hook procedure. |

### `lpfn` [in]

Type: **HOOKPROC**

A pointer to the hook procedure. If the *dwThreadId* parameter is zero or specifies the identifier of a thread created by a different process, the *lpfn* parameter must point to a hook procedure in a DLL. Otherwise, *lpfn* can point to a hook procedure in the code associated with the current process.

### `hmod` [in]

Type: **HINSTANCE**

A handle to the DLL containing the hook procedure pointed to by the *lpfn* parameter. The *hMod* parameter must be set to **NULL** if the *dwThreadId* parameter specifies a thread created by the current process and if the hook procedure is within the code associated with the current process.

### `dwThreadId` [in]

Type: **DWORD**

The identifier of the thread with which the hook procedure is to be associated. For desktop apps, if this parameter is zero, the hook procedure is associated with all existing threads running in the same desktop as the calling thread. For Windows Store apps, see the Remarks section.

## Return value

Type: **HHOOK**

If the function succeeds, the return value is the handle to the hook procedure.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetWindowsHookEx** can be used to inject a DLL into another process. A 32-bit DLL cannot be injected into a 64-bit process, and a 64-bit DLL cannot be injected into a 32-bit process. If an application requires the use of hooks in other processes, it is required that a 32-bit application call **SetWindowsHookEx** to inject a 32-bit DLL into 32-bit processes, and a 64-bit application call **SetWindowsHookEx** to inject a 64-bit DLL into 64-bit processes. The 32-bit and 64-bit DLLs must have different names.

Because hooks run in the context of an application, they must match the "bitness" of the application. If a 32-bit application installs a global hook on 64-bit Windows, the 32-bit hook is injected into each 32-bit process (the usual security boundaries apply). In a 64-bit process, the threads are still marked as "hooked." However, because a 32-bit application must run the hook code, the system executes the hook in the hooking app's context; specifically, on the thread that called **SetWindowsHookEx**. This means that the hooking application must continue to pump messages or it might block the normal functioning of the 64-bit processes.

If a 64-bit application installs a global hook on 64-bit Windows, the 64-bit hook is injected into each 64-bit process, while all 32-bit processes use a callback to the hooking application.

To hook all applications on the desktop of a 64-bit Windows installation, install a 32-bit global hook and a 64-bit global hook, each from appropriate processes, and be sure to keep pumping messages in the hooking application to avoid blocking normal functioning. If you already have a 32-bit global hooking application and it doesn't need to run in each application's context, you may not need to create a 64-bit version.

An error may occur if the *hMod* parameter is **NULL** and the *dwThreadId* parameter is zero or specifies the identifier of a thread created by another process.

Calling the [CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex) function to chain to the next hook procedure is optional, but it is highly recommended; otherwise, other applications that have installed hooks will not receive hook notifications and may behave incorrectly as a result. You should call **CallNextHookEx** unless you absolutely need to prevent the notification from being seen by other applications.

Before terminating, an application must call the [UnhookWindowsHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-unhookwindowshookex) function to free system resources associated with the hook.

The scope of a hook depends on the hook type. Some hooks can be set only with global scope; others can also be set for only a specific thread, as shown in the following table.

| Hook | Scope |
| --- | --- |
| **WH_CALLWNDPROC** | Thread or global |
| **WH_CALLWNDPROCRET** | Thread or global |
| **WH_CBT** | Thread or global |
| **WH_DEBUG** | Thread or global |
| **WH_FOREGROUNDIDLE** | Thread or global |
| **WH_GETMESSAGE** | Thread or global |
| **WH_JOURNALPLAYBACK** | Global only |
| **WH_JOURNALRECORD** | Global only |
| **WH_KEYBOARD** | Thread or global |
| **WH_KEYBOARD_LL** | Global only |
| **WH_MOUSE** | Thread or global |
| **WH_MOUSE_LL** | Global only |
| **WH_MSGFILTER** | Thread or global |
| **WH_SHELL** | Thread or global |
| **WH_SYSMSGFILTER** | Global only |

For a specified hook type, thread hooks are called first, then global hooks. Be aware that the WH_MOUSE, WH_KEYBOARD, WH_JOURNAL*, WH_SHELL, and low-level hooks can be called on the thread that installed the hook rather than the thread processing the hook. For these hooks, it is possible that both the 32-bit and 64-bit hooks will be called if a 32-bit hook is ahead of a 64-bit hook in the hook chain.

The global hooks are a shared resource, and installing one affects all applications in the same desktop as the calling thread. All global hook functions must be in libraries. Global hooks should be restricted to special-purpose applications or to use as a development aid during application debugging. Libraries that no longer need a hook should remove its hook procedure.

**Windows Store app development** If dwThreadId is zero, then window hook DLLs are not loaded in-process for the Windows Store app processes and the Windows Runtime broker process unless they are installed by either UIAccess processes (accessibility tools). The notification is delivered on the installer's thread for these hooks:

* WH_JOURNALPLAYBACK
* WH_JOURNALRECORD
* WH_KEYBOARD
* WH_KEYBOARD_LL
* WH_MOUSE
* WH_MOUSE_LL

This behavior is similar to what happens when there is an architecture mismatch between the hook DLL and the target application process, for example, when the hook DLL is 32-bit and the application process 64-bit.

#### Examples

For an example, see [Installing and Releasing Hook Procedures](https://learn.microsoft.com/windows/desktop/winmsg/using-hooks).

> [!NOTE]
> The winuser.h header defines SetWindowsHookEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CallNextHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callnexthookex)

[CallWindowProc function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowproca)

[UnhookWindowsHookEx function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-unhookwindowshookex)

[CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc)

[CallWndProc](https://learn.microsoft.com/windows/win32/winmsg/callwndproc)

[CallWndRetProc](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-hookproc)

[DebugProc](https://learn.microsoft.com/windows/win32/winmsg/debugproc)

[ForegroundIdleProc](https://learn.microsoft.com/windows/win32/winmsg/foregroundidleproc)

[GetMsgProc](https://learn.microsoft.com/windows/win32/winmsg/getmsgproc)

[JournalPlaybackProc](https://learn.microsoft.com/windows/win32/winmsg/journalplaybackproc)

[JournalRecordProc](https://learn.microsoft.com/windows/win32/winmsg/journalrecordproc)

[KeyboardProc](https://learn.microsoft.com/windows/win32/winmsg/keyboardproc)

[LowLevelKeyboardProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelkeyboardproc)

[LowLevelMouseProc](https://learn.microsoft.com/windows/win32/winmsg/lowlevelmouseproc)

[MessageProc](https://learn.microsoft.com/windows/win32/winmsg/messageproc)

[MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc)

[ShellProc](https://learn.microsoft.com/windows/win32/winmsg/shellproc)

[SysMsgProc](https://learn.microsoft.com/windows/win32/winmsg/sysmsgproc)

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)