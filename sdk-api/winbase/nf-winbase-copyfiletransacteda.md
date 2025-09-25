# CopyFileTransactedA function

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Copies an existing file to a new file as a transacted operation, notifying the application of its
progress through a callback function.

## Parameters

### `lpExistingFileName` [in]

The name of an existing file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.>.

If *lpExistingFileName* does not exist, the
**CopyFileTransacted** function fails, and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_FILE_NOT_FOUND**.

The file must reside on the local computer; otherwise, the function fails and the last error code is set to
**ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE**.

### `lpNewFileName` [in]

The name of the new file.

By default, the name is limited to MAX_PATH characters. To extend this limit to 32,767 wide characters, prepend "\\\\?\\" to the path. For more information, see [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file).

> [!TIP]
> Starting with Windows 10, Version 1607, you can opt-in to remove the MAX_PATH limitation without prepending "\\\\?\\". See the "Maximum Path Length Limitation" section of [Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/win32/fileio/naming-a-file) for details.

### `lpProgressRoutine` [in, optional]

The address of a callback function of type **LPPROGRESS_ROUTINE** that is called
each time another portion of the file has been copied. This parameter can be **NULL**. For
more information on the progress callback function, see the
[CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine) function.

### `lpData` [in, optional]

The argument to be passed to the callback function. This parameter can be
**NULL**.

### `pbCancel` [in, optional]

If this flag is set to **TRUE** during the copy operation, the operation is canceled.
Otherwise, the copy operation will continue to completion.

### `dwCopyFlags` [in]

Flags that specify how the file is to be copied. This parameter can be a combination of the following
values.

| Value | Meaning |
| --- | --- |
| **COPY_FILE_COPY_SYMLINK**<br><br>0x00000800 | If the source file is a symbolic link, the destination file is also a symbolic link pointing to the same file that the source symbolic link is pointing to. |
| **COPY_FILE_FAIL_IF_EXISTS**<br><br>0x00000001 | The copy operation fails immediately if the target file already exists. |
| **COPY_FILE_OPEN_SOURCE_FOR_WRITE**<br><br>0x00000004 | The file is copied and the original file is opened for write access. |
| **COPY_FILE_RESTARTABLE**<br><br>0x00000002 | Progress of the copy is tracked in the target file in case the copy fails. The failed copy can be restarted at a later time by specifying the same values for *lpExistingFileName* and *lpNewFileName* as those used in the call that failed. This can significantly slow down the copy operation as the new file may be flushed multiple times during the copy operation. |

### `hTransaction` [in]

A handle to the transaction. This handle is returned by the
[CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If *lpProgressRoutine* returns **PROGRESS_CANCEL** due to the
user canceling the operation, **CopyFileTransacted**
will return zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. In this case, the partially copied destination file is
deleted.

If *lpProgressRoutine* returns **PROGRESS_STOP** due to the
user stopping the operation, **CopyFileTransacted**
will return zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_REQUEST_ABORTED**. In this case, the partially copied destination file is left
intact.

If you attempt to call this function with a handle to a transaction that has already been rolled back,
**CopyFileTransacted** will return either
**ERROR_TRANSACTION_NOT_ACTIVE** or
**ERROR_INVALID_TRANSACTION**.

## Remarks

This function preserves extended attributes, OLE structured storage, NTFS file system alternate data streams,
security attributes, and file attributes.

**Windows 7, Windows Server 2008 R2, Windows Server 2008 and Windows Vista:** Security resource attributes (**ATTRIBUTE_SECURITY_INFORMATION**) for the existing
file are not copied to the new file until Windows 8 and Windows Server 2012.

This function fails with **ERROR_ACCESS_DENIED** if the destination file already exists
and has the **FILE_ATTRIBUTE_HIDDEN** or **FILE_ATTRIBUTE_READONLY**
attribute set.

Encrypted files are not supported by TxF.

If **COPY_FILE_COPY_SYMLINK** is specified, the following rules apply:

* If the source file is a symbolic link, the symbolic link is copied, not the target file.
* If the source file is not a symbolic link, there is no change in behavior.
* If the destination file is an existing symbolic link, the symbolic link is overwritten, not the target
  file.
* If **COPY_FILE_FAIL_IF_EXISTS** is also specified, and the destination file is an
  existing symbolic link, the operation fails in all cases.

If **COPY_FILE_COPY_SYMLINK** is not specified, the following rules apply:

* If **COPY_FILE_FAIL_IF_EXISTS** is also specified, and the destination file is an
  existing symbolic link, the operation fails only if the target of the symbolic link exists.
* If **COPY_FILE_FAIL_IF_EXISTS** is not specified, there is no change in
  behavior.

Link tracking is not supported by TxF.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

Note that SMB 3.0 does not support TxF.

> [!NOTE]
> The winbase.h header defines CopyFileTransacted as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine)

[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda)

[File Attribute Constants](https://learn.microsoft.com/windows/desktop/FileIO/file-attribute-constants)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)

[Symbolic Links](https://learn.microsoft.com/windows/desktop/FileIO/symbolic-links)

[Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/transactional-ntfs-portal)