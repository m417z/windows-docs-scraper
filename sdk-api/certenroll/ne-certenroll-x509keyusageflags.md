# X509KeyUsageFlags enumeration

## Description

The **X509KeyUsageFlags** enumeration type specifies the purpose of a key contained in a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). You can use the enumeration to identify restrictions. For example, if a key should be used only for signing, you can select the **XCN_CERT_DIGITAL_SIGNATURE_KEY_USAGE** or the **XCN_CERT_NON_REPUDIATION_KEY_USAGE** values. Likewise, if a key should be used only for key management, you can select the **XCN_CERT_KEY_ENCIPHERMENT_KEY_USAGE** value. This enumeration can be used to initialize an [IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage) object.

## Constants

### `XCN_CERT_NO_KEY_USAGE:0`

The purpose of the key is not defined.

### `XCN_CERT_DIGITAL_SIGNATURE_KEY_USAGE:0x80`

The key is used with a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) to support services other than nonrepudiation, certificate signing, or revocation list signing.

### `XCN_CERT_NON_REPUDIATION_KEY_USAGE:0x40`

The key is used to verify a [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) as part of a nonrepudiation service that protects against false denial of action by a signing entity.

### `XCN_CERT_KEY_ENCIPHERMENT_KEY_USAGE:0x20`

The key is used for key transport. That is, the key is used to manage a key passed from its point of origination to another point of use.

### `XCN_CERT_DATA_ENCIPHERMENT_KEY_USAGE:0x10`

The key is used to encrypt user data other than cryptographic keys.

### `XCN_CERT_KEY_AGREEMENT_KEY_USAGE:0x8`

The key is used for key agreement. The key agreement or key exchange protocol enables two or more parties to negotiate a key value without transferring the key and without previously establishing a shared secret.

### `XCN_CERT_KEY_CERT_SIGN_KEY_USAGE:0x4`

The key is used to verify a certificate signature. This value can only be used for certificates issued by [certification authorities](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `XCN_CERT_OFFLINE_CRL_SIGN_KEY_USAGE:0x2`

The key is used to verify an offline [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) signature.

### `XCN_CERT_CRL_SIGN_KEY_USAGE:0x2`

The key is used to verify a CRL signature.

### `XCN_CERT_ENCIPHER_ONLY_KEY_USAGE:0x1`

The key is used to encrypt data while performing key agreement. When this value is specified, the **XCN_CERT_KEY_AGREEMENT_KEY_USAGE** value must also be specified.

### `XCN_CERT_DECIPHER_ONLY_KEY_USAGE:0x8000`

The key is used to decrypt data while performing key agreement. When this value is specified, the **XCN_CERT_KEY_AGREEMENT_KEY_USAGE** must also be specified.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509ExtensionKeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionkeyusage)

[InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509extensionkeyusage-initializeencode)