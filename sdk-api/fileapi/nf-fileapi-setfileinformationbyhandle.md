# SetFileInformationByHandle function

## Description

Sets the file information for the specified file.

To retrieve file information using a file handle, see
[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle) or
[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex).

## Parameters

### `hFile` [in]

A handle to the file for which to change information.

This handle must be opened with the appropriate permissions for the requested change. For more information,
see the Remarks and Example Code sections.

This handle should not be a pipe handle.

### `FileInformationClass` [in]

A [FILE_INFO_BY_HANDLE_CLASS](https://learn.microsoft.com/windows/desktop/api/minwinbase/ne-minwinbase-file_info_by_handle_class) enumeration
value that specifies the type of information to be changed.

For a table of valid values, see the Remarks section.

### `lpFileInformation` [in]

A pointer to the buffer that contains the information to change for the specified file information class.
The structure that this parameter points to corresponds to the class that is specified by
*FileInformationClass*.

For a table of valid structure types, see the Remarks section.

### `dwBufferSize` [in]

The size of *lpFileInformation*, in bytes.

## Return value

Returns nonzero if successful or zero otherwise.

To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Certain file information classes behave slightly differently on different operating system releases. These
classes are supported by the underlying drivers, and any information they return is subject to change between
operating system releases.

The following table shows the valid file information classes and their corresponding data structure types for
use with this function.

| *FileInformationClass* value | *lpFileInformation* type |
| --- | --- |
| **FileBasicInfo**<br><br>0 | [FILE_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_basic_info) |
| **FileRenameInfo**<br><br>3 | [FILE_RENAME_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_rename_info) |
| **FileDispositionInfo**<br><br>4 | [FILE_DISPOSITION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_disposition_info) |
| **FileAllocationInfo**<br><br>5 | [FILE_ALLOCATION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_allocation_info) |
| **FileEndOfFileInfo**<br><br>6 | [FILE_END_OF_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_end_of_file_info) |
| **FileIoPriorityHintInfo**<br><br>12 | [FILE_IO_PRIORITY_HINT_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_io_priority_hint_info) |

You must specify appropriate access flags when creating the file handle for use with
**SetFileInformationByHandle**. For example, if
the application is using [FILE_DISPOSITION_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-file_disposition_info) with
the **DeleteFile** member set to **TRUE**, the file would need
**DELETE** access requested in the call to the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. To see an example of this, see the
Example Code section. For more information about file permissions, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

If there is a transaction bound to the handle, then the changes made will be transacted for the information
classes **FileBasicInfo**, **FileRenameInfo**,
**FileAllocationInfo**, **FileEndOfFileInfo**, and
**FileDispositionInfo**. If **FileDispositionInfo** is specified,
only the delete operation is transacted if a [DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea)
operation was requested. In this case, if the transaction is not committed before the handle is closed, the
deletion will not occur. For more information about TxF, see
[Transactional NTFS (TxF)](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | See comment |
| SMB 3.0 with Scale-out File Shares (SO) | See comment |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB 3.0 does not support rename of alternate data streams on file shares with continuous availability capability.

#### Examples

The following C++ example shows how to create a file and mark it for deletion when the handle is closed.

```cpp
//...
  HANDLE hFile = CreateFile( TEXT("tempfile"),
                             GENERIC_READ | GENERIC_WRITE | DELETE,
                             0 /* exclusive access */,
                             NULL,
                             CREATE_ALWAYS,
                             0,
                             NULL);

  if (hFile != INVALID_HANDLE_VALUE)
   {
    FILE_DISPOSITION_INFO fdi;
    fdi.DeleteFile = TRUE; // marking for deletion

    BOOL fResult = SetFileInformationByHandle( hFile,
                                               FileDispositionInfo,
                                               &fdi,
                                               sizeof(FILE_DISPOSITION_INFO) );

    if (fResult)
     {
      // File will be deleted upon CloseHandle.
      _tprintf( TEXT("SetFileInformationByHandle marked tempfile for deletion\n") );

      // ...
      // Now use the file for whatever temp data storage you need,
      // it will automatically be deleted upon CloseHandle or
      // application termination.
      // ...
     }
    else
     {
      _tprintf( TEXT("error %lu:  SetFileInformationByHandle could not mark tempfile for deletion\n"),
                GetLastError() );
     }

    CloseHandle(hFile);

    // At this point, the file is closed and deleted by the system.
   }
  else
   {
    _tprintf( TEXT("error %lu:  could not create tempfile\n"),
              GetLastError() );
 }
//...

```

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights)

[Generic Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights)

[GetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileinformationbyhandle)

[GetFileInformationByHandleEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getfileinformationbyhandleex)