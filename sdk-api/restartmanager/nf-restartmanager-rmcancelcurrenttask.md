# RmCancelCurrentTask function

## Description

Cancels the current [RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown) or [RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart) operation. This function must be called from the application that has started the session by calling the [RmStartSession](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmstartsession) function.

## Parameters

### `dwSessionHandle` [in]

A handle to an existing session.

## Return value

This is the most recent error received. The function can return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that are defined in Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | A cancellation of the current operation is requested. |
| **ERROR_BAD_ARGUMENTS**<br><br>160 | One or more arguments are not correct. This error value is returned by the Restart Manager function if a **NULL** pointer or 0 is passed in a parameter that requires a non-**null** and non-zero value. |
| **ERROR_OUTOFMEMORY**<br><br>14 | A Restart Manager operation could not complete because not enough memory was available. |
| **ERROR_INVALID_HANDLE**<br><br>6 | No Restart Manager session exists for the handle supplied. |

## See also

[RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart)

[RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown)