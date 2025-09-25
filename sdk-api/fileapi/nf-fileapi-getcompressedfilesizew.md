# GetCompressedFileSizeW function

## Description

Retrieves the actual number of bytes of disk storage used to store a specified file. If the file is located on a volume that supports compression and the file is compressed, the value obtained is the compressed size of the specified file. If the file is located on a volume that supports sparse files and the file is a sparse file, the value obtained is the sparse size of the specified file.

To perform this operation as a transacted operation, use the [GetCompressedFileSizeTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcompressedfilesizetransacteda) function.

## Parameters

### `lpFileName` [in]

The name of the file.

Do not specify the name of a file on a nonseeking device, such as a pipe or a communications device, as its file size has no meaning.

This parameter may include the path.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpFileSizeHigh` [out, optional]

The high-order **DWORD** of the compressed file size. The function's return value is the low-order **DWORD** of the compressed file size.

This parameter can be **NULL** if the high-order **DWORD** of the compressed file size is not needed. Files less than 4 gigabytes in size do not need the high-order **DWORD**.

## Return value

If the function succeeds, the return value is the low-order **DWORD** of the actual number of bytes of disk storage used to store the specified file, and if *lpFileSizeHigh* is non-**NULL**, the function puts the high-order **DWORD** of that actual value into the **DWORD** pointed to by that parameter. This is the compressed file size for compressed files, the actual file size for noncompressed files.

If the function fails, and *lpFileSizeHigh* is **NULL**, the return value is **INVALID_FILE_SIZE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the return value is **INVALID_FILE_SIZE** and *lpFileSizeHigh* is non-**NULL**, an application must call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine whether the function has succeeded (value is **NO_ERROR**) or failed (value is other than **NO_ERROR**).

## Remarks

An application can determine whether a volume is compressed by calling
[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa), then checking the status of the **FS_VOL_IS_COMPRESSED** flag in the **DWORD** value pointed to by that function's *lpFileSystemFlags* parameter.

If the file is not located on a volume that supports compression or sparse files, or if the file is not compressed or a sparse file, the value obtained is the actual file size, the same as the value returned by a call to
[GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize).

Symbolic link behavior—If the path points to a symbolic link, the function returns the file size of the target.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

> [!NOTE]
> The fileapi.h header defines GetCompressedFileSize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Compression and Decompression](https://learn.microsoft.com/windows/desktop/FileIO/file-compression-and-decompression)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[GetCompressedFileSizeTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcompressedfilesizetransacteda)

[GetFileSize](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfilesize)

[GetVolumeInformation](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getvolumeinformationa)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)