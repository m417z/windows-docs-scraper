# SetupCancelTemporarySourceList function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCancelTemporarySourceList** function cancels any temporary list and no-browse behavior and reestablishes standard list behavior.

## Return value

If a temporary list was in effect, the return value is a nonzero value. Otherwise, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)