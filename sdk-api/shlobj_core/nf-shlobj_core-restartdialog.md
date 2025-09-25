# RestartDialog function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Displays a dialog box that prompts the user to restart Windows. When the user clicks the button, the function calls [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) to attempt to restart Windows.

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

A handle to the parent window.

### `pszPrompt` [in, optional]

Type: **PCWSTR**

A null-terminated Unicode string that contains the text that displays in the dialog box which prompts the user.

### `dwReturn`

Type: **DWORD**

The flags that specify the type of shutdown.

This parameter must include one of the following values.

#### EWX_LOGOFF

Shuts down all processes running in the security context of the process that called this function, then logs the user off.

#### EWX_POWEROFF

Shuts down the system and turns off the power. The system must support the power-off feature. The calling process must have the **SE_SHUTDOWN_NAME** privilege. For more information, see [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex).

#### EWX_REBOOT

Shuts down the system and then restarts the system. The calling process must have the **SE_SHUTDOWN_NAME** privilege. For more information, see [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex).

#### EWX_SHUTDOWN

Shuts down the system to a point at which it is safe to turn off the power. At this point, all file buffers have been flushed to disk, and all running processes have stopped. If the system supports the power-off feature, the power is also turned off. The calling process must have the **SE_SHUTDOWN_NAME** privilege. For more information, see [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex).

This parameter can optionally include the following values.

#### EWX_FORCE

Forces processes to terminate. When this flag is set, the system does not send the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) and [WM_ENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-endsession) messages. This can cause the applications to lose data. Therefore, you should only use this flag in an emergency.

#### EWX_FORCEIFHUNG

Forces processes to terminate if they do not respond to the [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) or [WM_ENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-endsession) message. This flag is ignored if **EWX_FORCE** is used.

## Return value

Type: **int**

Returns the identifier of the button that was pressed to close the dialog box.