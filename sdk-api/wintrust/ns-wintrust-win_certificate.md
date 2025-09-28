# WIN_CERTIFICATE structure

## Description

This structure encapsulates a signature used in verifying executable files.

## Members

### `dwLength`

Specifies the length, in bytes, of the signature.

### `wRevision`

Specifies the certificate revision.

The defined certificate revisions are **WIN_CERT_REVISION_1_0 (0x0100)** and **WIN_CERT_REVISION_2_0 (0x0200)**.

### `wCertificateType`

Specifies the type of certificate.

| Value | Description |
| --- | --- |
| WIN_CERT_TYPE_X509 (0x0001) | The *bCertificate* member contains an X.509 certificate. |
| WIN_CERT_TYPE_PKCS_SIGNED_DATA (0x0002) | The *bCertificate* member contains a PKCS **SignedData** structure. |
| WIN_CERT_TYPE_RESERVED_1 (0x0003) | Reserved. |
| WIN_CERT_TYPE_PKCS1_SIGN (0x0009) | The *bCertificate* member contains **PKCS1_MODULE_SIGN** fields. |

### `bCertificate`

An array of certificates.

The format of this member depends on the value of *wCertificateType*.