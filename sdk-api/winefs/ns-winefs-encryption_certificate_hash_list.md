# ENCRYPTION_CERTIFICATE_HASH_LIST structure

## Description

Contains a list of certificate hashes.

## Members

### `nCert_Hash`

The number of certificate hashes in the list.

### `nCert_Hash.range`

### `nCert_Hash.range.0`

### `nCert_Hash.range.500`

### `pUsers`

A pointer to the first
[ENCRYPTION_CERTIFICATE_HASH](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash) structure in the list.

### `pUsers.size_is`

### `pUsers.size_is.nCert_Hash`

## See also

[ENCRYPTION_CERTIFICATE_HASH](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[FreeEncryptionCertificateHashList](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-freeencryptioncertificatehashlist)

[QueryRecoveryAgentsOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryrecoveryagentsonencryptedfile)

[QueryUsersOnEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-queryusersonencryptedfile)

[RemoveUsersFromEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-removeusersfromencryptedfile)