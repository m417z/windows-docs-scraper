# InitiateSystemShutdownExW function

## Description

Initiates a shutdown and optional restart of the specified computer, and optionally records the reason for the shutdown.

## Parameters

### `lpMachineName` [in, optional]

The network name of the computer to be shut down. If *lpMachineName* is **NULL** or an empty string, the function shuts down the local computer.

### `lpMessage` [in, optional]

The message to be displayed in the shutdown dialog box. This parameter can be **NULL** if no message is required.

**Windows Server 2003 and Windows XP:** This string is also stored as a comment in the event log entry.

**Windows Server 2003 and Windows XP with SP1:** The string is limited to 3072 **TCHARs**.

### `dwTimeout` [in]

The length of time that the shutdown dialog box should be displayed, in seconds. While this dialog box is displayed, shutdown can be stopped by the
[AbortSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-abortsystemshutdowna) function.

If *dwTimeout* is not zero,
**InitiateSystemShutdownEx** displays a dialog box on the specified computer. The dialog box displays the name of the user who called the function, displays the message specified by the *lpMessage* parameter, and prompts the user to log off. The dialog box beeps when it is created and remains on top of other windows in the system. The dialog box can be moved but not closed. A timer counts down the remaining time before shutdown.

If *dwTimeout* is zero, the computer shuts down without displaying the dialog box, and the shutdown cannot be stopped by
[AbortSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-abortsystemshutdowna).

**Windows Server 2003 and Windows XP with SP1:** The time-out value is limited to MAX_SHUTDOWN_TIMEOUT seconds.

**Windows Server 2003 and Windows XP with SP1:** If the computer to be shut down is a Terminal Services server, the system displays a dialog box to all local and remote users warning them that shutdown has been initiated. The dialog box includes who requested the shutdown, the display message (see *lpMessage*), and how much time there is until the server is shut down.

### `bForceAppsClosed` [in]

If this parameter is **TRUE**, applications with unsaved changes are to be forcibly closed. If this parameter is **FALSE**, the system displays a dialog box instructing the user to close the applications.

### `bRebootAfterShutdown` [in]

If this parameter is **TRUE**, the computer is to restart immediately after shutting down. If this parameter is **FALSE**, the system flushes all caches to disk and safely powers down the system.

### `dwReason` [in]

The reason for initiating the shutdown. This parameter must be one of the
[system shutdown reason codes](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-reason-codes).

If this parameter is zero, the default is an undefined shutdown that is logged as "No title for this reason could be found". By default, it is also an unplanned shutdown. Depending on how the system is configured, an unplanned shutdown triggers the creation of a file that contains the system state information, which can delay shutdown. Therefore, do not use zero for this parameter.

**Windows XP:** System state information is not saved during an unplanned system shutdown. The preceding text does not apply.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege. To shut down a remote computer, the calling thread must have the SE_REMOTE_SHUTDOWN_NAME privilege on the remote computer. By default, users can enable the SE_SHUTDOWN_NAME privilege on the computer they are logged onto, and administrators can enable the SE_REMOTE_SHUTDOWN_NAME privilege on remote computers. For more information, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Common reasons for failure include an invalid or inaccessible computer name or insufficient privilege. The error ERROR_SHUTDOWN_IN_PROGRESS is returned if a shutdown is already in progress on the specified computer. The error ERROR_NOT_READY can be returned if fast-user switching is enabled but no user is logged on.

A non-zero return value does not mean the logoff was or will be successful. The shutdown is an asynchronous process, and it can occur long after the API call has returned, or not at all. Even if the timeout value is zero, the shutdown can still be aborted by applications, services, or even the system. The non-zero return value indicates that the validation of the rights and parameters was successful and that the system accepted the shutdown request.

When this function is called, the caller must specify whether or not applications with unsaved changes should be forcibly closed. If the caller chooses not to force these applications to close and an application with unsaved changes is running on the console session, the shutdown will remain in progress until the user logged into the console session aborts the shutdown, saves changes, closes the application, or forces the application to close. During this period the shutdown may not be aborted except by the console user, and another shutdown may not be initiated.

Note that calling this function with the value of the *bForceAppsClosed* parameter set to **TRUE** avoids this situation. Remember that doing this may result in loss of data.

**Windows Server 2003 and Windows XP:** If the computer is locked and the *bForceAppsClosed* parameter is **FALSE**, the last error code is ERROR_MACHINE_LOCKED. If the system is not ready to handle the request, the last error code is ERROR_NOT_READY. The application should wait a short while and retry the call. For example, the system can be unready to initiate a shutdown, and return ERROR_NOT_READY, if the shutdown request comes at the same time a user tries to log onto the system. In this case, the application should wait a short while and retry the call.

> [!NOTE]
> The winreg.h header defines InitiateSystemShutdownEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AbortSystemShutdown](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-abortsystemshutdowna)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)

[System Shutdown Functions](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-functions)