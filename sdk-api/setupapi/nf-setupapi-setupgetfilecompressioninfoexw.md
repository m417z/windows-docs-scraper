# SetupGetFileCompressionInfoExW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupGetFileCompressionInfoEx** function examines a potentially compressed file and gets the type of compression, the file's full path (including file name), the compressed size, and the size of the uncompressed target file. The caller of the function passes in the name of the file to be examined and pointers to locations for the buffer and buffer size to receive the returned file name and path.

To determine the size of the buffer for the returned path and file name, you can call
**SetupGetFileCompressionInfoEx** with *ActualSourceFileNameBuffer* specified **Null** and *ActualSourceFileNameLen* containing 0. The function succeeds and on return fills in *RequiredBufferLen*.

## Parameters

### `SourceFileName` [in]

File name of the potentially compressed file to be examined. If the file is not found on the source media exactly as named, Setup searches for up to two alternate names. For example; if Setup does not find F:\x86\cmd.exe, it searches for F:\mpis\cmd.ex_ and if that name is not found, it searches for F:\x86\cmd.ex$.

### `ActualSourceFileNameBuffer` [in, out]

Pointer to a buffer that receives the actual file name and path if this parameter is not **NULL**. This is valid only if the function returns NO_ERROR.

### `ActualSourceFileNameBufferLen` [in, out]

Size of the buffer specified by *ActualSourceFileNameBuffer*, in characters. You would typically use a buffer size of MAX_PATH. If *ActualSourceFileNameLen* is too small, the function fails with ERROR_INSUFFICIENT_BUFFER. *ActualSourceFileNameLen* must contain zero if *ActualSourceFileNameBuffer* is **NULL**.

### `RequiredBufferLen` [out]

Size of the file name and full path including the terminating **NULL**, if this parameter is not **NULL**. If *ActualSourceFileNameBuffer* is **NULL** and *ActualSourceFileNameLen* is zero, the function succeeds but fills in *RequiredBufferLen*. This parameter is valid only if the function returns NO_ERROR or ERROR_INSUFFICIENT_BUFFER.

### `SourceFileSize` [out]

Pointer to a variable in which this function returns the size of the file in its current form, which is the current size of the file named by *ActualSourceFileNameBuffer*. The size is determined by examining the source file; it is not retrieved from an INF file. The source file size is valid only if the function returns NO_ERROR or ERROR_INSUFFICIENT_BUFFER.

### `TargetFileSize` [out]

Pointer to a variable in which this function returns the size that the file will occupy when it is uncompressed or copied. If the file is not compressed, this value will be the same as *SourceFileSize*. The size is determined by examining the file; it is not retrieved from an INF file. The target file size is valid only if the function returns NO_ERROR or ERROR_INSUFFICIENT_BUFFER.

### `CompressionType` [out]

Pointer to a variable in which this function returns a value indicating the type of compression used on *ActualSourceFileName*. The compression type is valid only if the function returns NO_ERROR or ERROR_INSUFFICIENT_BUFFER. This parameter value can be one of the following flags.

#### FILE_COMPRESSION_NONE

The source file is not compressed with a recognized compression algorithm.

#### FILE_COMPRESSION_WINLZA

The source file is compressed with LZ compression.

#### FILE_COMPRESSION_MSZIP

The source file is compressed with MSZIP compression.

##### - CompressionType.FILE_COMPRESSION_MSZIP

The source file is compressed with MSZIP compression.

##### - CompressionType.FILE_COMPRESSION_NONE

The source file is not compressed with a recognized compression algorithm.

##### - CompressionType.FILE_COMPRESSION_WINLZA

The source file is compressed with LZ compression.

## Return value

If the function succeeds, the return value is **TRUE** (nonzero).

If the function fails, the return value is **FALSE** (zero). The function can also return one of the following [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Because
**SetupGetFileCompressionInfoEx** determines the compression by examining the physical file, your setup application should ensure that the file is present before calling
**SetupGetFileCompressionInfoEx**.

> [!NOTE]
> The setupapi.h header defines SetupGetFileCompressionInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupDecompressOrCopyFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdecompressorcopyfilea)