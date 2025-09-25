# SetupGetInfFileListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetInfFileList** function returns a list of INF files located in a caller-specified directory to a call-supplied buffer.

## Parameters

### `DirectoryPath` [in]

Optional pointer to a **null**-terminated string containing the path of the directory in which to search. If this value is **NULL**, the %windir%\inf directory is used.

### `InfStyle` [in]

Type of INF file to search for. May be a combination of the following flags.

#### INF_STYLE_OLDNT

A legacy INF file format.

#### INF_STYLE_WIN4

A Windows INF file format.

### `ReturnBuffer` [in, out]

 If not **NULL**, points to a buffer in which this function returns the list of all INF files of the desired styles that were found in the specified subdirectory. File names are **null**-terminated, with an extra **null** at the end of the list. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. Using this technique, you can avoid errors due to an insufficient buffer size. The filenames do not include the path. See the Remarks section.

### `ReturnBufferSize` [in]

Size of the buffer pointed to by the *ReturnBuffer* parameter, in characters. This includes the **null** terminator. If *ReturnBuffer* is not specified, *ReturnBufferSize* is ignored.

### `RequiredSize` [in, out]

If not **NULL**, points to a variable in which this function returns the required size for the buffer pointed to by the *ReturnBuffer* parameter, in characters. This includes the **null** terminator. If *ReturnBuffer* is specified and the size needed is larger than *ReturnBufferSize*, the function fails and a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a ReturnBuffer of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If multiple INF file styles are returned by this function, the style of a particular INF file can be determined by calling the [SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa) function

> [!NOTE]
> The setupapi.h header defines SetupGetInfFileList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa)