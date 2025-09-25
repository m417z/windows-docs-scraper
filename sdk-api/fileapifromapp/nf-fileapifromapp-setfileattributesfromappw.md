## Description

Sets the attributes for a file or directory. The behavior of this function is identical to [**SetFileAttributes**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-setfileattributesw), except that this function adheres to the Universal Windows Platform app security model.

## Parameters

### `lpFileName`

The name of the file whose attributes are to be set.
For information about opting out of the **MAX\_PATH** limitation without prepending "\\\\?\\", see the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `dwFileAttributes`

The file attributes to set for the file.
This parameter can be one or more values, combined using the bitwise-OR operator. However, all other values override **FILE\_ATTRIBUTE\_NORMAL**.

Not all attributes are supported by this function.

The following is a list of supported attribute values.

| Value | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE** 32 (0x20) | A file or directory that is an archive file or directory. Applications typically use this attribute to mark files for backup or removal. |
| **FILE_ATTRIBUTE_HIDDEN** 2 (0x2) | The file or directory is hidden. It is not included in an ordinary directory listing. |
| **FILE_ATTRIBUTE_NORMAL** 128 (0x80) | A file that does not have other attributes set. This attribute is valid only when used alone. |
| **FILE_ATTRIBUTE_NOT_CONTENT_INDEXED** 8192 (0x2000) | The file or directory is not to be indexed by the content indexing service. |
| **FILE_ATTRIBUTE_OFFLINE** 4096 (0x1000) | The data of a file is not available immediately. This attribute indicates that the file data is physically moved to offline storage. This attribute is used by Remote Storage, which is the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| **FILE_ATTRIBUTE_READONLY** 1 (0x1) | A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not honored on directories. |
| **FILE_ATTRIBUTE_SYSTEM** 4 (0x4) | A file or directory that the operating system uses a part of, or uses exclusively. |
| **FILE_ATTRIBUTE_TEMPORARY** 256 (0x100) | A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also