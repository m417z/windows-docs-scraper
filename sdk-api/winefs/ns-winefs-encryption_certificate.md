# ENCRYPTION_CERTIFICATE structure

## Description

Contains a certificate and the SID of its owner.

## Members

### `cbTotalLength`

The length of this structure, in bytes.

### `pUserSid`

The [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) of the user who owns the certificate.

### `pCertBlob`

A pointer to an
[EFS_CERTIFICATE_BLOB](https://learn.microsoft.com/windows/win32/api/winefs/ns-winefs-efs_certificate_blob) structure.

## See also

[EFS_CERTIFICATE_BLOB](https://learn.microsoft.com/windows/win32/api/winefs/ns-winefs-efs_certificate_blob)

[ENCRYPTION_CERTIFICATE_LIST](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate_list)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[SetUserFileEncryptionKey](https://learn.microsoft.com/windows/desktop/api/winefs/nf-winefs-setuserfileencryptionkey)