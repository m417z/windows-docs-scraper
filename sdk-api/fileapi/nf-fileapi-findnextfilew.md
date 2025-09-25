# FindNextFileW function

## Description

Continues a file search from a previous call to the
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea),
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa), or
[FindFirstFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-findfirstfiletransacteda) functions.

## Parameters

### `hFindFile` [in]

The search handle returned by a previous call to the
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) or
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function.

### `lpFindFileData` [out]

A pointer to the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure
that receives information about the found file or subdirectory.

## Return value

If the function succeeds, the return value is nonzero and the *lpFindFileData*
parameter contains information about the next file or directory found.

If the function fails, the return value is zero and the contents of *lpFindFileData*
are indeterminate. To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If the function fails because no more matching files can be found, the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_NO_MORE_FILES**.

## Remarks

This function uses the same search filters that were used to create the search handle passed in the
*hFindFile* parameter. For additional information, see
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) and
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa).

The order in which the search returns the files, such as alphabetical order, is not guaranteed, and is
dependent on the file system. If the data must be sorted,
the application must do the ordering after obtaining all the results.

**Note** In rare cases or on a heavily loaded system, file attribute information on NTFS file systems may not be
current at the time this function is called. To be assured of getting the current NTFS file system file
attributes, call the
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) function.

The order in which this function returns the file names is dependent on the file system type. With the NTFS
file system and CDFS file systems, the names are usually returned in alphabetical order. With FAT file systems,
the names are usually returned in the order the files were written to the disk, which may or may not be in
alphabetical order. However, as stated previously, these behaviors are not guaranteed.

If the path points to a symbolic link, the
[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) buffer contains information about the
symbolic link, not the target.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

### Transacted Operations

If there is a transaction bound to the file enumeration handle, then the files that are returned are subject
to transaction isolation rules.

#### Examples

For an example, see
[Listing the Files in a Directory](https://learn.microsoft.com/windows/desktop/FileIO/listing-the-files-in-a-directory).

> [!NOTE]
> The fileapi.h header defines FindNextFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa)

[GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa)

[SetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileattributesa)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa)