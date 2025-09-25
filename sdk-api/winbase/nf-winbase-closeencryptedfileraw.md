# CloseEncryptedFileRaw function

## Description

Closes an encrypted file after a backup
or restore operation, and frees associated system resources. This is one of a group of Encrypted File System (EFS) functions that is intended to implement backup and restore functionality, while maintaining files in their encrypted state.

## Parameters

### `pvContext` [in]

A pointer to a system-defined context block. The
[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa) function returns the context block.

## Remarks

The **CloseEncryptedFileRaw** function frees allocated system resources
such as the system-defined context block and closes the file.

The [BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread) and [BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) functions handle backup and restore of unencrypted files.

In Windows 8, Windows Server 2012, and later, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

Note that SMB 3.0 does not support EFS on shares with continuous availability capability.

## See also

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)