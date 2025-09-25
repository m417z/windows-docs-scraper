# X509PrivateKeyUsageFlags enumeration

## Description

The **X509PrivateKeyUsageFlags** enumeration specifies the permitted uses of a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). It is the responsibility of the cryptographic provider. The enumeration value can be set and retrieved by using the [KeyUsage](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyusage) property on the [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interface.

## Constants

### `XCN_NCRYPT_ALLOW_USAGES_NONE:0`

The permitted uses are not defined.

### `XCN_NCRYPT_ALLOW_DECRYPT_FLAG:0x1`

The key can be used to decrypt content. This maps to the following [X509KeyUsageFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyusageflags) values:

* XCN_CERT_DATA_ENCIPHERMENT_KEY_USAGE
* XCN_CERT_DECIPHER_ONLY_KEY_USAGE
* XCN_CERT_ENCIPHER_ONLY_KEY_USAGE
* XCN_CERT_KEY_ENCIPHERMENT_KEY_USAGE

### `XCN_NCRYPT_ALLOW_SIGNING_FLAG:0x2`

The key can be used for signing. This maps to the following [X509KeyUsageFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyusageflags) values:

* XCN_CERT_CRL_SIGN_KEY_USAGE
* XCN_CERT_DIGITAL_SIGNATURE_KEY_USAGE
* XCN_CERT_KEY_CERT_SIGN_KEY_USAGE

### `XCN_NCRYPT_ALLOW_KEY_AGREEMENT_FLAG:0x4`

The key can be used to establish key agreement between entities.

### `XCN_NCRYPT_ALLOW_KEY_IMPORT_FLAG:0x8`

### `XCN_NCRYPT_ALLOW_ALL_USAGES:0xffffff`

All of the uses defined for this enumeration are permitted.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)