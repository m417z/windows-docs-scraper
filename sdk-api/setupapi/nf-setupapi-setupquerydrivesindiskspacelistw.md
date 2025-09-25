# SetupQueryDrivesInDiskSpaceListW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueryDrivesInDiskSpaceList** function fills a buffer with a list of the drives referenced by the file operations listed in the disk-space list.

## Parameters

### `DiskSpace` [in]

Handle to the disk-space list.

### `ReturnBuffer` [in, out]

Optional pointer to a buffer that receives the drive specifications, such as "X:" or "\\server\share". You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. This parameter can be **NULL**.
If this parameter is not specified and no error occurs, the function returns a nonzero value and *RequiredSize* receives the buffer size required to hold the drive specifications.

### `ReturnBufferSize` [in]

Size of the buffer pointed by *ReturnBuffer*, in characters. This includes the **null** terminator. This parameter is ignored if *ReturnBuffer* is not specified.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the size of the buffer required to hold the **null**-terminated list of drives, in characters. This includes the **null** terminator.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns ERROR_INSUFFICIENT_BUFFER, *ReturnBuffer* was specified, but *ReturnBufferSize* indicated that the supplied buffer was too small.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupQuerySpaceRequiredOnDrive](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryspacerequiredondrivea)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupQueryDrivesInDiskSpaceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).