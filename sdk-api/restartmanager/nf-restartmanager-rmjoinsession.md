# RmJoinSession function

## Description

Joins a secondary installer to an existing Restart Manager session. This function must be called with a session key that can only be obtained from the primary installer that started the session. A valid session key is required to use any of the Restart Manager functions. After a secondary installer joins a session, it can call the [RmRegisterResources](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmregisterresources) function to register resources.

## Parameters

### `pSessionHandle` [out]

A pointer to the handle of an existing Restart Manager Session.

### `strSessionKey` [in]

A **null**-terminated string that contains the session key of an existing session.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_SESSION_CREDENTIAL_CONFLICT**<br><br>1219 | The session key cannot be validated. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_BAD_ARGUMENTS**<br><br>22 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_MAX_SESSIONS_REACHED**<br><br>353 | The maximum number of sessions has been reached. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |

## Remarks

The **RmJoinSession** function joins a secondary installer to an existing Restart Manager session. This is typically an installer that does not control the user interface and can run either in-process or out-of-process of the primary installer. Only the primary installer can call the [RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function and this is typically the application that controls the user interface or that controls the installation sequence of multiple patches in an update.

## See also

[RmEndSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmendsession)

[RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession)