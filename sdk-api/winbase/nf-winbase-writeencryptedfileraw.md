# WriteEncryptedFileRaw function

## Description

Restores (import) encrypted files. This is one of a group of Encrypted File System (EFS)
functions that is intended to implement backup and restore functionality, while maintaining files in their
encrypted state.

## Parameters

### `pfImportCallback` [in]

A pointer to the import callback function. The system calls the callback function multiple times, each time
passing a buffer that will be filled by the callback function with a portion of backed-up file's data. When the
callback function signals that the entire file has been processed, it tells the system that the restore
operation is finished. For more information, see
[ImportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_import_func).

### `pvCallbackContext` [in, optional]

A pointer to an application-defined and allocated context block. The system passes this pointer to the
callback function as a parameter so that the callback function can have access to application-specific data.
This can be a structure and can contain any data the application needs, such as the handle to the file that will
contain the backup copy of the encrypted file.

### `pvContext` [in]

A pointer to a system-defined context block. The context block is returned by the
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa) function. Do not modify
it.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, it returns a nonzero error code defined in WinError.h. You can use
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the
**FORMAT_MESSAGE_FROM_SYSTEM** flag to get a generic text description of the error.

## Remarks

The file being restored is not decrypted; it is restored in its encrypted state.

To back up an encrypted file, call
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa) to open the file. Then call
[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw), passing it the address of an
application-defined export callback function. The system calls this callback function multiple times until the
entire file's contents have been read and backed up. When the backup is complete, call
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw) to free resources and close
the file. See [ExportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_export_func) for details about how to
declare the export callback function.

To restore an encrypted file, call
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa), specifying
**CREATE_FOR_IMPORT** in the *ulFlags* parameter. Then call
**WriteEncryptedFileRaw**, passing it the address of
an application-defined import callback function. The system calls this callback function multiple times until the
entire file's contents have been read and restored. When the restore is complete, call
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw) to free resources and close
the file. See [ImportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_import_func) for details about how to
declare the export callback function.

If the file is a sparse file that was backed up from a volume with a smaller sparse allocation unit size than
the volume it is being restored to, the sparse blocks in the middle of the file may not properly align with the
larger blocks and the function call would fail and set an **ERROR_INVALID_PARAMETER** last
error code. The sparse allocation unit size is either 16 clusters or 64 KB, whichever is smaller.

This function is intended for restoring only encrypted files; see
[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) for restoring unencrypted files.

In Windows 8, Windows Server 2012, and later, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

## See also

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)

[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[ImportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_import_func)

[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)