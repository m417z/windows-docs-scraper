# SetUserFileEncryptionKey function

## Description

Sets the user's current key to the specified certificate.

## Parameters

### `pEncryptionCertificate` [in]

A pointer to a certificate that will be the user's key. This parameter is a pointer to an
[ENCRYPTION_CERTIFICATE](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate) structure.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a system error code. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB 3.0 does not support EFS on shares with continuous availability capability.

## See also

[ENCRYPTION_CERTIFICATE](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)