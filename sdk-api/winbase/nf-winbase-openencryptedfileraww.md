# OpenEncryptedFileRawW function

## Description

Opens an encrypted file in order to backup (export) or restore (import)
the file. This is one of a group of Encrypted File System (EFS) functions that is intended to implement backup and restore functionality, while maintaining files in their encrypted state.

## Parameters

### `lpFileName` [in]

The name of the file to be opened. The string must consist of characters from the Windows character set.

### `ulFlags` [in]

The operation to be performed. This parameter may be one of the
following values.

| Value | Meaning |
| --- | --- |
| 0 | Open the file for export (backup). |
| **CREATE_FOR_IMPORT**<br><br>1 | The file is being opened for import (restore). |
| **CREATE_FOR_DIR**<br><br>2 | Import (restore) a directory containing encrypted files. This must be combined with one of the previous two flags to indicate the operation. |
| **OVERWRITE_HIDDEN**<br><br>4 | Overwrite a hidden file on import. |

### `pvContext` [out]

The address of a context
block that must be presented in subsequent calls to
[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw), [WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw), or
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw). Do not modify it.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns a nonzero error code defined in
WinError.h. You can use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) with the
**FORMAT_MESSAGE_FROM_SYSTEM** flag to get a generic text description of
the error.

## Remarks

The caller must either have read or write access to the file, or it must have backup privilege [SeBackupPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) on the machine on which the files reside in order for the call to succeed.

To back up an encrypted file, call **OpenEncryptedFileRaw** to open the
file and then call [ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw). When the backup is
complete, call [CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw).

To restore an encrypted file, call **OpenEncryptedFileRaw**, specifying
**CREATE_FOR_IMPORT** in the *ulFlags* parameter, and then call
[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw) once. When the operation is completed, call
[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw).

**OpenEncryptedFileRaw** fails if *lpFileName* exceeds **MAX_PATH** characters when opening an encrypted file on a remote machine.

 If the caller does not have access to the key for the file, the caller needs [SeBackupPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants) to export encrypted files or SeRestorePrivilege to import encrypted files.

The [BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread) and [BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite) functions handle backup and restore of unencrypted files.

In Windows 8, Windows Server 2012, and later, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

> [!NOTE]
> The winbase.h header defines OpenEncryptedFileRaw as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BackupRead](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupread)

[BackupWrite](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupwrite)

[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)