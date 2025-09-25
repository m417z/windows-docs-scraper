# FreeEncryptionCertificateHashList function

## Description

Frees a certificate hash list.

## Parameters

### `pUsers` [in]

A pointer to a certificate hash list structure,
[ENCRYPTION_CERTIFICATE_HASH_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash_list), which was returned by the
[QueryUsersOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryusersonencryptedfile) or
[QueryRecoveryAgentsOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryrecoveryagentsonencryptedfile) function.

## Remarks

**ReFS:** This function is not supported.

## See also

[ENCRYPTION_CERTIFICATE_HASH_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash_list)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[QueryRecoveryAgentsOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryrecoveryagentsonencryptedfile)

[QueryUsersOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryusersonencryptedfile)