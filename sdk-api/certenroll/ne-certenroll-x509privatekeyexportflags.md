# X509PrivateKeyExportFlags enumeration

## Description

The **X509PrivateKeyExportFlags** enumeration type specifies the export policy for a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). For a Cryptography API: Next Generation (CNG) key, the policy is stored by the key service provider (KSP), and it is the responsibility of the KSP to enforce the policy. When a legacy [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) is specified, the policy is used when creating the key, and it is the responsibility of the CSP to enforce the policy. This enumeration is used when specifying and retrieving the [ExportPolicy](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_exportpolicy) property on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface.

## Constants

### `XCN_NCRYPT_ALLOW_EXPORT_NONE:0`

Export is not allowed. This is the default value.

### `XCN_NCRYPT_ALLOW_EXPORT_FLAG:0x1`

The private key can be exported.

### `XCN_NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG:0x2`

The private key can be exported in plaintext form.

### `XCN_NCRYPT_ALLOW_ARCHIVING_FLAG:0x4`

The private key can be exported once for archiving.

### `XCN_NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG:0x8`

The private key can be exported once in plaintext form for archiving.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)