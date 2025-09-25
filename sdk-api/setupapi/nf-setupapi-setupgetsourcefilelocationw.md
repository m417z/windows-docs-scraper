# SetupGetSourceFileLocationW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetSourceFileLocation** function retrieves the location of a source file listed in an INF file.

## Parameters

### `InfHandle` [in]

Handle to the INF file that contains the **SourceDisksNames** and **SourceDisksFiles** sections. If platform-specific sections exist for the user's system (for example, **SourceDisksNames.x86** and **SourceDisksFiles.x86**), the platform-specific section will be used.

### `InfContext` [in]

Optional pointer to the context of a line in a **Copy Files** section for which the full source path is to be retrieved. If this parameter is **NULL**, *FileName* is searched for in the **SourceDisksFiles** section of the INF file specified by *InfHandle*.

### `FileName` [in]

Optional pointer to a **null**-terminated string containing the filename (no path) for which to return the full source location. This parameter can be **NULL**, but either *FileName* or *InfContext* must be specified.

### `SourceId` [in, out]

Pointer to a variable that receives the source identifier of the media where the file is located from the **SourceDisksNames** section of the INF file.

### `ReturnBuffer` [in, out]

 Optional pointer to a buffer to receive the relative source path. The source path does not include the filename itself, nor does it include a drive letter/network share name. The path does not start or end with a backslash (\), so the empty string specifies the root directory. You should use a **null**-terminated string buffer. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. See the Remarks section. This parameter can be **NULL**.

### `ReturnBufferSize` [out]

Size of the buffer pointed to by *ReturnBuffer*, in characters. This number includes the **null** terminator.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the required size for the buffer pointed to by the *ReturnBuffer* parameter, in characters. This number includes the **null** terminator. If the required size is larger than the value specified by *ReturnBufferSize*, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *ReturnBuffer* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

> [!NOTE]
> The setupapi.h header defines SetupGetSourceFileLocation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetSourceFileSize](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilesizea)

[SetupGetSourceInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourceinfoa)