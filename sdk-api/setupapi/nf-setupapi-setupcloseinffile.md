# SetupCloseInfFile function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupCloseInfFile** function closes the INF file opened by a call to
[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea). This function closes any INF files appended to it by
calling [SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea).

## Parameters

### `InfHandle` [in]

Handle to the INF file to be closed.

## Return value

This function does not return a value.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea)

[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea)