# PFNSTATUSMESSAGECALLBACK callback function

## Description

The
**StatusMessageCallback** function is an application-defined callback function used to display status messages when applying policy. The **PFNSTATUSMESSAGECALLBACK** type defines a pointer to this callback function.
**StatusMessageCallback** is a placeholder for the application-defined function name.

## Parameters

### `bVerbose` [in]

Specifies whether the message is verbose. If this parameter is **TRUE**, the message is verbose. If this parameter is **FALSE**, the message is not verbose.

### `lpMessage` [in]

Pointer to a buffer that contains the message string.

## Return value

If the message was displayed successfully, return **ERROR_SUCCESS**. Otherwise, return a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Pass a pointer to the
**StatusMessageCallback** function when the system calls the
[ProcessGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicy) or the
[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex) callback function.

The status user interface has two modes: standard and verbose. Verbose messages are displayed only when the computer is in verbose mode. To enable verbose mode, set the following registry value to 1, log out, and log on. There is no need to restart the computer.

**HKEY_LOCAL_MACHINE**\**Software**\**Microsoft**\**Windows NT**\**CurrentVersion**\**Winlogon**\**VerboseStatus**

**Warning** Do not call the
**StatusMessageCallback** function from a background thread because you may overwrite another thread's status message.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[ProcessGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicy)

[ProcessGroupPolicyEx](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfnprocessgrouppolicyex)