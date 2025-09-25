# ReadEncryptedFileRaw function

## Description

Backs up (export) encrypted files. This is one of a group of Encrypted File System (EFS)
functions that is intended to implement backup and restore functionality, while maintaining files in their
encrypted state.

## Parameters

### `pfExportCallback` [in]

A pointer to the export callback function. The system calls the callback function multiple times, each time
passing a block of the file's data to the callback function until the entire file has been read. For more
information, see [ExportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_export_func).

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

The file being backed up is not decrypted; it is backed up in its encrypted state.

To back up an encrypted file, call
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa) to open the file. Then call
**ReadEncryptedFileRaw**, passing it the address of an
application-defined export callback function. The system calls this callback function multiple times until the
entire file's contents have been read and backed up. When the backup is complete, call
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw) to free resources and close
the file. See [ExportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_export_func) for details about how to
declare the export callback function.

To restore an encrypted file, call
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa), specifying
**CREATE_FOR_IMPORT** in the *ulFlags* parameter. Then call
[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw), passing it the address of
an application-defined import callback function. The system calls this callback function multiple times until the
entire file's contents have been read and restored. When the restore is complete, call
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw) to free resources and close
the file. See [ImportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_import_func) for details about how to
declare the import callback function.

This function is intended for the backup of only encrypted files; see
[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread) for backup of unencrypted files.

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

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)