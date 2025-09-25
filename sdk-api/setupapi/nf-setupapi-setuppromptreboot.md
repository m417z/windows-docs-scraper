# SetupPromptReboot function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupPromptReboot** function asks the user if he wants to reboot the system, optionally dependent on whether any files in a committed file queue were in use during a file operation. If the user answers "yes" to the prompt, shutdown is initiated before this routine returns.

## Parameters

### `FileQueue` [in]

Optional pointer to a handle to the file queue upon which to base the decision about whether shutdown is necessary. If *FileQueue* is not specified,
**SetupPromptReboot** assumes shutdown is necessary and asks the user what to do.

### `Owner` [in]

Handle for the parent window to own windows created by this function.

### `ScanOnly` [in]

Indicates whether or not to prompt the user when
**SetupPromptReboot** is called.

If **TRUE**, the user is never asked about rebooting, and system shutdown is not initiated. In this case, *FileQueue* must be specified. If **FALSE**, the user is asked about rebooting, as previously described.

Use *ScanOnly* to determine if shutdown is necessary separately from actually initiating a shutdown.

## Return value

The function returns a combination of the following flags or –1 if an error occurs.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupPromptForDisk](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptfordiska)