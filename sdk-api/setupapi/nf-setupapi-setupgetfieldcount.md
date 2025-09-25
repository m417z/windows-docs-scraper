# SetupGetFieldCount function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetFieldCount** function retrieves the number of fields in the specified line in an INF file.

## Parameters

### `Context` [in]

Pointer to the context for a line in an INF file.

## Return value

This function returns the number of fields on the line. If *Context* is invalid, 0 is returned. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetLineCount](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetlinecounta)