# WTSShutdownSystem function

## Description

Shuts down (and optionally restarts) the specified Remote Desktop Session Host (RD Session Host) server.

To shut down or restart the system, the calling process must have the **SE_SHUTDOWN_NAME** privilege enabled. For more information about security privileges, see
[Privileges](https://learn.microsoft.com/windows/desktop/SecAuthZ/privileges) and
[Authorization Constants](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

## Parameters

### `hServer` [in]

Handle to an RD Session Host server. Specify a handle opened by the
[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera) function, or specify **WTS_CURRENT_SERVER_HANDLE** to indicate the RD Session Host server on which your application is running.

### `ShutdownFlag` [in]

Indicates the type of shutdown. This parameter can be one of the following values.

#### WTS_WSD_LOGOFF

Forces all client sessions to log off (except the session calling
**WTSShutdownSystem**) and disables any subsequent remote logons. This can be used as a step before shutting down. Logons will be re-enabled when the Remote Desktop Services service is restarted.

Use this value only on the Remote Desktop Services console.

#### WTS_WSD_POWEROFF

Shuts down the system on the RD Session Host server and, on computers that support software control of AC power, turns off the power. This is equivalent to calling [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) with **EWX_SHUTDOWN** and **EWX_POWEROFF**. The calling process must have the **SE_SHUTDOWN_NAME** privilege enabled.

#### WTS_WSD_REBOOT

Shuts down and then restarts the system on the RD Session Host server. This is equivalent to calling **ExitWindowsEx** with **EWX_REBOOT**. The calling process must have the **SE_SHUTDOWN_NAME** privilege enabled.

#### WTS_WSD_SHUTDOWN

Shuts down the system on the RD Session Host server. This is equivalent to calling the
[ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function with **EWX_SHUTDOWN**. The calling process must have the **SE_SHUTDOWN_NAME** privilege enabled.

#### WTS_WSD_FASTREBOOT

This value is not supported currently.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A system shutdown terminates all users and active programs. The following steps occur during shutdown.

1. An exit command is issued to all active user applications.
2. If the application does not exit within a specific interval, the application is terminated.
3. After all the applications for a user terminate, the user is logged off.
4. After all users are logged off, an exit command is issued to all system services.
5. If the system service does not terminate within a specific interval, the service is terminated.
6. The file system cache is written to disk.
7. The disks are marked read-only.
8. The RD Session Host server displays the message "It is now safe to turn off your computer", or the system is restarted if **WTS_WSD_REBOOT** is specified. (The message is displayed on the console because all client sessions have been terminated.)

**Note** Because there can be many users and processes in a large multiple-user configuration, large system configurations may take some time to shut down in an orderly fashion. It is important to allow the system to shut down completely.

**Windows Server 2008 and Windows Vista:** A call to **WTSShutdownSystem** does not work when Remote Connection Manager (RCM) is disabled. This is the case when the Remote Desktop Services service is stopped.

## See also

[ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex)