# X509PrivateKeyProtection enumeration

## Description

The **X509PrivateKeyProtection** enumeration specifies the level of [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) protection supported by a cryptographic provider. For example, if strong key protection is enabled, the user is typically prompted to enter a password when the key is created and whenever the key is used. The precise behavior is specified by the KSP or CSP being used. The enumeration value can be specified or retrieved by using the [KeyProtection](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyprotection) property on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface.

## Constants

### `XCN_NCRYPT_UI_NO_PROTECTION_FLAG:0`

The protection level is not specified.

### `XCN_NCRYPT_UI_PROTECT_KEY_FLAG:0x1`

A user interface is displayed to indicate that a process is attempting to use the key. The exact behavior is specified by the KSP or CSP being used. Some Microsoft legacy CSPs allow the client to decide whether a password is required to use the key or whether the user must only acknowledge a prompt.

### `XCN_NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG:0x2`

Specifies strong key protection. The user is typically prompted to enter a password when the key is created and whenever the key is used. The exact behavior is specified by the KSP being used. This value is not supported by the Certificate Enrollment API for legacy CSPs.

### `XCN_NCRYPT_UI_FINGERPRINT_PROTECTION_FLAG:0x4`

### `XCN_NCRYPT_UI_APPCONTAINER_ACCESS_MEDIUM_FLAG:0x8`

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)