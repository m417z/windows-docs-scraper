# KeyIdentifierHashAlgorithm enumeration

## Description

The **KeyIdentifierHashAlgorithm** enumeration type specifies the algorithm used to [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) in a [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This enumeration is used by the [ComputeKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-computekeyidentifier) method on the [IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey) interface, and the key identifier can be used to initialize the [IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier) and [IX509ExtensionAuthorityKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionauthoritykeyidentifier) objects.

## Constants

### `SKIHashDefault:0`

The default hash algorithm. This is redundant with the **SKIHashSha1** value.

### `SKIHashSha1:1`

A 160-bit SHA-1 hash of a [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded public key, excluding the tag, length, and number of unused bits.

### `SKIHashCapiSha1:2`

A 160-bit SHA-1 hash of a DER-encoded public key, including the tag, length, and number of unused bits.

### `SKIHashSha256:3`

A 256-bit SHA256 (SHA-2) hash of a DER-encoded public key, including the tag, length, and number of unused bits.

### `SKIHashHPKP:5`

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[ComputeKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509publickey-computekeyidentifier)

[IX509ExtensionAuthorityKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionauthoritykeyidentifier)

[IX509ExtensionSubjectKeyIdentifier](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extensionsubjectkeyidentifier)

[IX509PublicKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509publickey)