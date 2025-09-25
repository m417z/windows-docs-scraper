# AddUsersToEncryptedFile function

## Description

Adds user keys to the specified encrypted file.

## Parameters

### `lpFileName` [in]

The name of the encrypted file.

### `pEncryptionCertificates` [in]

A pointer to an
[ENCRYPTION_CERTIFICATE_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_list) structure that contains the list of new user keys to be added to the file.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a system error code. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

Starting with Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

#### Examples

For example code that uses this function, see [Adding Users to an Encrypted File](https://learn.microsoft.com/windows/desktop/FileIO/adding-users-to-an-encrypted-file).

## See also

[ENCRYPTION_CERTIFICATE_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_list)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)