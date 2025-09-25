# WIN32_FIND_DATAW structure

## Description

Contains information about the file that is found by the
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea),
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa), or
[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea) function.

## Members

### `dwFileAttributes`

The file attributes of a file.

For possible values and their descriptions, see
[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants).

The **FILE_ATTRIBUTE_SPARSE_FILE** attribute on the file is set if any of the streams
of the file have ever been sparse.

### `ftCreationTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies when a file or
directory was created.

If the underlying file system does not support creation time, this member is zero.

### `ftLastAccessTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

For a file, the structure specifies when the file was last read from, written to, or for executable files,
run.

For a directory, the structure specifies when the directory is created. If the underlying file system does
not support last access time, this member is zero.

On the FAT file system, the specified date for both files and directories is correct, but the time of day is
always set to midnight.

### `ftLastWriteTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

For a file, the structure specifies when the file was last written to, truncated, or overwritten, for
example, when [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) or
[SetEndOfFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setendoffile) are used. The date and time are not
updated when file attributes or security descriptors are changed.

For a directory, the structure specifies when the directory is created. If the underlying file system does
not support last write time, this member is zero.

### `nFileSizeHigh`

The high-order **DWORD** value of the file size, in bytes.

This value is zero unless the file size is greater than **MAXDWORD**.

The size of the file is equal to (**nFileSizeHigh** *
(**MAXDWORD**+1)) + **nFileSizeLow**.

### `nFileSizeLow`

The low-order **DWORD** value of the file size, in bytes.

### `dwReserved0`

If the **dwFileAttributes** member includes the
**FILE_ATTRIBUTE_REPARSE_POINT** attribute, this member specifies the reparse point
tag.

Otherwise, this value is undefined and should not be used.

For more information see [Reparse Point Tags](https://learn.microsoft.com/windows/desktop/FileIO/reparse-point-tags).

#### IO_REPARSE_TAG_CSV (0x80000009)

#### IO_REPARSE_TAG_DEDUP (0x80000013)

#### IO_REPARSE_TAG_DFS (0x8000000A)

#### IO_REPARSE_TAG_DFSR (0x80000012)

#### IO_REPARSE_TAG_HSM (0xC0000004)

#### IO_REPARSE_TAG_HSM2 (0x80000006)

#### IO_REPARSE_TAG_MOUNT_POINT (0xA0000003)

#### IO_REPARSE_TAG_NFS (0x80000014)

#### IO_REPARSE_TAG_SIS (0x80000007)

#### IO_REPARSE_TAG_SYMLINK (0xA000000C)

#### IO_REPARSE_TAG_WIM (0x80000008)

### `dwReserved1`

Reserved for future use.

### `cFileName`

The name of the file.

### `cAlternateFileName`

An alternative name for the file.

This name is in the classic 8.3 file name format.

### `dwFileType`

Obsolete. Do not use.

### `dwCreatorType`

Obsolete. Do not use.

### `wFinderFlags`

Obsolete. Do not use.

## Syntax

```
typedef struct _WIN32_FIND_DATAW {
  DWORD    dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD    nFileSizeHigh;
  DWORD    nFileSizeLow;
  DWORD    dwReserved0;
  DWORD    dwReserved1;
  WCHAR    cFileName[MAX_PATH];
  WCHAR    cAlternateFileName[14];
  DWORD    dwFileType; // Obsolete. Do not use.
  DWORD    dwCreatorType; // Obsolete. Do not use
  WORD     wFinderFlags; // Obsolete. Do not use
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
```

## Remarks

If a file has a long file name, the complete name appears in the **cFileName** member,
and the 8.3 format truncated version of the name appears in the **cAlternateFileName**
member. Otherwise, **cAlternateFileName** is empty. If the
[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa) function was called with a value of
**FindExInfoBasic** in the *fInfoLevelId* parameter, the
**cAlternateFileName** member will always contain a **NULL** string
value. This remains true for all subsequent calls to the
[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea) function. As an alternative method of
retrieving the 8.3 format version of a file name, you can use the
[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew) function. For more information about
file names, see [File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

Not all file systems can record creation and last access times, and not all file systems record them in the
same manner. For example, on the FAT file system, create time has a resolution of 10 milliseconds, write time has
a resolution of 2 seconds, and access time has a resolution of 1 day. The
NTFS file system delays updates to the last access time for a file by up to 1 hour after the last access. For
more information, see [File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

> [!NOTE]
> The minwinbase.h header defines WIN32_FIND_DATA as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

[File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times)

[FileTimeToLocalFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime)

[FileTimeToSystemTime](https://learn.microsoft.com/windows/desktop/api/timezoneapi/nf-timezoneapi-filetimetosystemtime)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[FindFirstFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfileexa)

[FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea)

[GetShortPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getshortpathnamew)