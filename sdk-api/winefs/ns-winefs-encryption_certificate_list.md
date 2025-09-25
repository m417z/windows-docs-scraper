# ENCRYPTION_CERTIFICATE_LIST structure

## Description

Contains a list of certificates.

## Members

### `nUsers`

The number of certificates in the list.

### `nUsers.range`

### `nUsers.range.0`

### `nUsers.range.500`

### `pUsers`

A pointer to the first
[ENCRYPTION_CERTIFICATE](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate) structure in the list.

### `pUsers.size_is`

### `pUsers.size_is.nUsers`

## See also

[AddUsersToEncryptedFile](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-adduserstoencryptedfile)

[ENCRYPTION_CERTIFICATE](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)