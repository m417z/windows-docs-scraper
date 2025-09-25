# SetupGetTargetPathA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetTargetPath** function determines the target directory for a file list section. The file list section can be a **Copy Files** section, a **Delete Files** section, or a **Rename Files** section. All the files in the section must be in a single directory that is listed in a **DestinationDirs** section of the INF file.

## Parameters

### `InfHandle` [in]

Handle to the load INF file that contains a **DestinationDirs** section.

### `InfContext` [in]

Optional pointer to an INF context that specifies a line in a file list section whose destination directory is to be retrieved. If *InfContext* is **NULL**, then the *Section* parameter is used.

### `Section` [in]

Optional parameter that specifies the name of a section of the INF file whose handle is *InfHandle*.
**SetupGetTargetPath** retrieves the target directory for this section. The *Section* parameter is ignored if *InfContext* is specified. If neither *InfContext* nor *Section* is specified, the function retrieves the default target path from the INF file. You should use a **null**-terminated string.

### `ReturnBuffer` [in, out]

Optional pointer to buffer to receive the fully qualified target path. The path is guaranteed not to end with \. You should use a **null**-terminated string. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the required size for the buffer pointed to by *ReturnBuffer*, in characters. This includes the **null** terminator. If the actual size needed is larger than the value specified by *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

> [!NOTE]
> The setupapi.h header defines SetupGetTargetPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetSourceFileLocation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilelocationa)

[SetupGetSourceFileSize](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilesizea)

[SetupGetSourceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourceinfoa)