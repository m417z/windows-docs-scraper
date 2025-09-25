# QueryRecoveryAgentsOnEncryptedFile function

## Description

Retrieves a list of recovery agents for the specified file.

## Parameters

### `lpFileName` [in]

The name of the file.

### `pRecoveryAgents` [out]

A pointer to a
[ENCRYPTION_CERTIFICATE_HASH_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash_list) structure that receives a list of recovery agents.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is a system error code. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

When the list of recovery agents is no longer needed, free it by calling the
[FreeEncryptionCertificateHashList](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-freeencryptioncertificatehashlist) function.

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

[ENCRYPTION_CERTIFICATE_HASH_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash_list)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[FreeEncryptionCertificateHashList](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-freeencryptioncertificatehashlist)