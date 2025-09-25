# ENCRYPTION_CERTIFICATE_HASH structure

## Description

Contains a certificate hash and display information for the certificate.

## Members

### `cbTotalLength`

The length of this structure, in bytes.

### `pUserSid`

The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) of the user who created the certificate. This member is optional and can be **NULL**.

### `pHash`

A pointer to an
[EFS_HASH_BLOB](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-efs_hash_blob) structure.

### `lpDisplayInformation`

User-displayable information for the certificate. This is usually the user's common name and universal principal name (UPN).

### `lpDisplayInformation.string`

## See also

[EFS_HASH_BLOB](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-efs_hash_blob)

[ENCRYPTION_CERTIFICATE_HASH_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_hash_list)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)