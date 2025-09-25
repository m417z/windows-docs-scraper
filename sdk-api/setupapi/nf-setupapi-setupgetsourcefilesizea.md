# SetupGetSourceFileSizeA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetSourceFileSize** function reads the uncompressed size of a source file listed in an INF file.

## Parameters

### `InfHandle` [in]

Handle to the loaded INF file that contains the **SourceDisksNames** and **SourceDisksFiles** sections. If platform-specific sections exist for the user's system (for example, **SourceDisksNames.x86** and **SourceDisksFiles.x86**), the platform-specific section will be used.

### `InfContext` [in]

Optional pointer to a context for a line in a **Copy Files** section for which the size is to be retrieved. If *InfContext* is **NULL**, the *FileName* parameter is used.

### `FileName` [in]

Optional pointer to a **null**-terminated string containing the filename (no path) for which to return the size. If this parameter is **NULL** as well as *InfContext*, then the *Section* parameter is used.

### `Section` [in]

Optional pointer to a **null**-terminated string containing the name of a **Copy Files** section. If this parameter is specified, the total size of all files listed in the section is computed.

### `FileSize` [in, out]

Pointer to a variable that receives the size, in bytes, of the specified file(s).

### `RoundingFactor` [in]

Optional value for rounding file sizes. All file sizes are rounded up to a multiple of this number before being added to the total size. Rounding is useful for more exact determinations of the space that a file will occupy on a given volume, because it allows the caller to have file sizes rounded up to a multiple of the cluster size. Rounding does not occur unless *RoundingFactor* is specified.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

One and only one of the optional parameters, *InfContext*, *FileName*, and *Section*, must be specified.

> [!NOTE]
> The setupapi.h header defines SetupGetSourceFileSize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetSourceFileLocation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetsourcefilelocationa)