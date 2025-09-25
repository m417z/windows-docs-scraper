# SetupOpenLog function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The **SetupOpenLog** function opens the log files.

## Parameters

### `Erase` [in]

Must be FALSE.

## Return value

**TRUE** if the log file can be opened. **FALSE** if an error occurs. To get the error code, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 The log files are located in the Windows directory, and the file names are Setupact.log and Setuperr.log.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)