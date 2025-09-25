# EFS_CERTIFICATE_BLOB structure

## Description

Contains a certificate.

## Members

### `dwCertEncodingType`

A certificate encoding type. This member can be one of the following values.

#### CRYPT_ASN_ENCODING

#### CRYPT_NDR_ENCODING

#### X509_ASN_ENCODING

#### X509_NDR_ENCODING

### `cbData`

The number of bytes in the **pbData** buffer.

### `cbData.range`

### `cbData.range.0`

### `cbData.range.32768`

### `pbData`

The binary certificate. The
**dwCertEncodingType** member specifies the format for this certificate.

### `pbData.size_is`

### `pbData.size_is.cbData`

## See also

[ENCRYPTION_CERTIFICATE](https://learn.microsoft.com/windows/desktop/api/winefs/ns-winefs-encryption_certificate)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)