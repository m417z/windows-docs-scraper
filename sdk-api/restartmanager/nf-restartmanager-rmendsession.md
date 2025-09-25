# RmEndSession function

## Description

Ends the Restart Manager session. This function should be called by the primary installer that has previously started the session by calling the [RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function. The **RmEndSession** function can be called by a secondary installer that is joined to the session once no more resources need to be registered by the secondary installer.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing Restart Manager session.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The function completed successfully. |
| **ERROR_SEM_TIMEOUT**<br><br>121 | A Restart Manager function could not obtain a Registry write mutex in the allotted time. A system restart is recommended because further use of the Restart Manager is likely to fail. |
| **ERROR_WRITE_FAULT**<br><br>29 | An operation was unable to read or write to the registry. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | An invalid handle was passed to the function. No Restart Manager session exists for the handle supplied. |

## See also

[RmJoinSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmjoinsession)

[RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession)