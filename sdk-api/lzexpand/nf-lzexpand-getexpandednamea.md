# GetExpandedNameA function

## Description

Retrieves the original name of a compressed file, if the file was compressed by the Lempel-Ziv algorithm.

## Parameters

### `lpszSource` [in]

The name of the compressed file.

### `lpszBuffer` [out]

A pointer to a buffer that receives the original name of the compressed file.

## Return value

If the function succeeds, the return value is 1.

If the function fails, the return value is LZERROR_BADVALUE. There is no extended error information for this function; do not call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

**Note** **GetExpandedName** calls neither
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) nor
[SetLastErrorEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setlasterrorex); thus, its failure does not affect a thread's last-error code.

## Remarks

The contents of the buffer pointed to by the *lpszBuffer* parameter is the original file name if the file was compressed by using the **/r** option. If the **/r** option was not used, this function duplicates the name in the *lpszSource* parameter into the *lpszBuffer* buffer.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The lzexpand.h header defines GetExpandedName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)