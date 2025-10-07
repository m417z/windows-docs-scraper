# SeStopImpersonatingClient routine

The **SeStopImpersonatingClient** routine ends the calling thread's impersonation of a user.

## Parameters

This routine has no parameters.

## Return value

None

## Remarks

A server thread can impersonate a user by calling the [**SeImpersonateClientEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seimpersonateclientex) routine. When the thread is done impersonating the user, it calls the **SeStopImpersonatingClient** routine to end the impersonation.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Minimum supported client | Windows XP |
| Header | *Ntifs.h* (include *Ntifs.h*) |
| IRQL | PASSIVE_LEVEL |

## See also

[**SeImpersonateClientEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seimpersonateclientex)