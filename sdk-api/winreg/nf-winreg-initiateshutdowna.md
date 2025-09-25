# InitiateShutdownA function

## Description

Initiates a shutdown and restart of the specified computer, and restarts any applications that have been registered for restart.

## Parameters

### `lpMachineName` [in, optional]

The name of the computer to be shut down. If the value of this parameter is **NULL**, the local computer is shut down.

### `lpMessage` [in, optional]

The message to be displayed in the interactive shutdown dialog box.

### `dwGracePeriod` [in]

The number of seconds to wait before shutting down the computer. If the value of this parameter is zero, the computer is shut down immediately. This value is limited to **MAX_SHUTDOWN_TIMEOUT**.

If the value of this parameter is greater than zero, and the *dwShutdownFlags* parameter specifies the flag **SHUTDOWN_GRACE_OVERRIDE**, the function fails and returns the error code **ERROR_BAD_ARGUMENTS**.

### `dwShutdownFlags` [in]

One or more bit flags that specify options for the shutdown. The following values are defined.

| Value | Meaning |
| --- | --- |
| **SHUTDOWN_FORCE_OTHERS**<br><br>0x00000001 (0x1) | All sessions are forcefully logged off. If this flag is not set and users other than the current user are logged on to the computer specified by the *lpMachineName* parameter, this function fails with a return value of **ERROR_SHUTDOWN_USERS_LOGGED_ON**. |
| **SHUTDOWN_FORCE_SELF**<br><br>0x00000002 (0x2) | Specifies that the originating session is logged off forcefully. If this flag is not set, the originating session is shut down interactively, so a shutdown is not guaranteed even if the function returns successfully. |
| **SHUTDOWN_GRACE_OVERRIDE**<br><br>0x00000020 (0x20) | Overrides the grace period so that the computer is shut down immediately. |
| **SHUTDOWN_HYBRID**<br><br>0x00000200 (0x200) | Beginning with **InitiateShutdown** running on Windows 8, you must include the **SHUTDOWN_HYBRID** flag with one or more of the flags in this table to specify options for the shutdown. <br><br>Beginning with Windows 8, **InitiateShutdown** always initiate a full system shutdown if the **SHUTDOWN_HYBRID** flag is absent. |
| **SHUTDOWN_INSTALL_UPDATES**<br><br>0x00000040 (0x40) | The computer installs any updates before starting the shutdown. |
| **SHUTDOWN_NOREBOOT**<br><br>0x00000010 (0x10) | The computer is shut down but is not powered down or rebooted. |
| **SHUTDOWN_POWEROFF**<br><br>0x00000008 (0x8) | The computer is shut down and powered down. |
| **SHUTDOWN_RESTART**<br><br>0x00000004 (0x4) | The computer is shut down and rebooted. |
| **SHUTDOWN_RESTARTAPPS**<br><br>0x00000080 (0x80) | The system is rebooted using the [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function with the EWX_RESTARTAPPS flag. This restarts any applications that have been registered for restart using the [RegisterApplicationRestart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrestart) function. |

### `dwReason` [in]

The reason for initiating the shutdown. This parameter must be one of the [system shutdown reason codes](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-reason-codes).
If this parameter is zero, the default is an undefined shutdown that is logged as "No title for this reason could be found". By default, it is also an unplanned shutdown. Depending on how the system is configured, an unplanned shutdown triggers the creation of a file that contains the system state information, which can delay shutdown. Therefore, do not use zero for this parameter.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the required privilege (SE_SHUTDOWN_PRIVILEGE or SE_REMOTE_SHUTDOWN_PRIVILEGE) to perform this operation. |
| **ERROR_BAD_NETPATH** | The specified computer does not exist or is not accessible. |
| **ERROR_INVALID_COMPUTERNAME** | The specified computer name is not a valid computer name. |
| **ERROR_INVALID_FUNCTION** | The specified computer does not support a shutdown interface. |
| **ERROR_INVALID_PARAMETER** | An invalid set of parameters was passed. This includes the following combinations.<br><br>* The *lpMachineName* parameter specifies a remote computer, and the *dwShutdownFlags* parameter does not specify **SHUTDOWN_FORCE_SELF**.<br>* The value of the *dwGracePeriod* is greater than zero and the *dwShutdownFlags* parameter does not specify **SHUTDOWN_FORCE_SELF**.<br>* The value of the *dwGracePeriod* is greater than zero and the *dwShutdownFlags* parameter specifies **SHUTDOWN_GRACE_OVERRIDE**. |
| **ERROR_SHUTDOWN_IN_PROGRESS** | A shutdown has already been started on the specified computer. |
| **ERROR_SHUTDOWN_IS_SCHEDULED** | A shutdown for the specified computer has been scheduled but not started. For this function to succeed, the **SHUTDOWN_GRACE_OVERRIDE** flag must be set. |
| **ERROR_SHUTDOWN_USERS_LOGGED_ON** | One or more users other than the current user are logged on the specified machine, and the **SHUTDOWN_FORCE_OTHERS** flag was not set. |

## Remarks

To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege. To shut down a remote computer, the calling thread must have the SE_REMOTE_SHUTDOWN_NAME privilege on the remote computer. By default, users can enable the SE_SHUTDOWN_NAME privilege on the computer they are logged onto, and administrators can enable the SE_REMOTE_SHUTDOWN_NAME privilege on remote computers. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Common reasons for failure include an invalid or inaccessible computer name or insufficient privilege. The error ERROR_SHUTDOWN_IN_PROGRESS is returned if a shutdown is already in progress on the specified computer. The error ERROR_NOT_READY can be returned if fast-user switching is enabled but no user is logged on.

A non-zero return value does not mean the logoff was or will be successful. The shutdown is an asynchronous process, and it can occur long after the API call has returned, or not at all. Even if the timeout value is zero, the shutdown can still be aborted by applications, services, or even the system. The non-zero return value indicates that the validation of the rights and parameters was successful and that the system accepted the shutdown request.

> [!NOTE]
> The winreg.h header defines InitiateShutdown as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)