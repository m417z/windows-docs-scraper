# SetupDecompressOrCopyFileW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupDecompressOrCopyFile** function copies a file, decompressing it if necessary.

If a file is copied, the caller of this function is required have privileges to write into the target directory.

## Parameters

### `SourceFileName` [in]

File name of the file to be copied. You should use a **null**-terminated string. This parameter can be **NULL**. If *CompressionType* is not specified and the
**SetupDecompressOrCopyFile** function does not find the file specified in *SourceFileName*, the function searches for the file with up to two alternate, "compressed-form" names. For example, if the file is F:\x86\cmd.exe and it is not found, the function searches for F:\x86\cmd.ex_ and, if that is not found, F:\x86\cmd.ex$ is searched for. If *CompressionType* is specified, no additional processing is performed on the filename; the file must exist exactly as specified or the function fails.

### `TargetFileName` [in]

Exact name of the target file that will be created by decompressing or copying the source file. You should use a **null**-terminated string.

### `CompressionType` [in]

Optional pointer to the compression type used on the source file. You can determine the compression type by calling
[SetupGetFileCompressionInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetfilecompressioninfoa). If this value is FILE_COMPRESSION_NONE, the file is copied (not decompressed) regardless of any compression in use on the source. If *CompressionType* is not specified, this routine determines the compression type automatically.

## Return value

The
**SetupDecompressOrCopyFile** function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that indicates the outcome of the operation.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupGetFileCompressionInfo](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetfilecompressioninfoa)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupDecompressOrCopyFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).