# SetupOpenMasterInf function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupOpenMasterInf** function opens the master INF file that contains file and layout information for files shipped with Windows.

## Return value

If
**SetupOpenMasterInf** is successful, it returns a handle to the opened INF file that contains file/layout information for files shipped with Windows. Otherwise, the return value is INVALID_HANDLE_VALUE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea)

[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea)