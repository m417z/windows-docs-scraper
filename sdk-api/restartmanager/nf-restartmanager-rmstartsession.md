# RmStartSession function

## Description

Starts a new Restart Manager session. A maximum of 64 Restart Manager sessions per user session can be open on the system at the same time. When this function starts a session, it returns a session handle and session key that can be used in subsequent calls to the Restart Manager API.

## Parameters

### `pSessionHandle` [out]

A pointer to the handle of a Restart Manager session. The session handle can be passed in subsequent calls to the Restart Manager API.

### `dwSessionFlags`

Reserved. This parameter should be 0.

### `strSessionKey` [out]

A **null**-terminated string that contains the session key to the new session. The string of size `CCH_RM_SESSION_KEY + 1` must be allocated before calling the **RmStartSession** function.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_MAX_SESSIONS_REACHED**<br><br>353 | The maximum number of sessions has been reached. |
| **ERROR_WRITE_FAULT**<br><br>29 | The system cannot write to the specified device. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |

## Remarks

The **RmStartSession** function returns an error if a session with the same session key already exists.

The **RmStartSession** function should be called by the primary installer that controls the user interface or that controls the installation sequence of multiple patches in an update.

A secondary installer can join an existing Restart Manager session by calling the [RmJoinSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmjoinsession) function with the session handle and session key returned from the **RmStartSession** function call of the primary installer.

## See also

[RmEndSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmendsession)

[RmJoinSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmjoinsession)