# ObjectIdPublicKeyFlags enumeration

## Description

The **ObjectIdPublicKeyFlags** enumeration type specifies whether a [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) algorithm is used for signing or for [encryption](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). Some algorithms, such as [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), can be used for both purposes. This enumeration is used by the [InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname) method on the [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface to narrow and disambiguate the algorithm search.

## Constants

### `XCN_CRYPT_OID_INFO_PUBKEY_ANY:0`

The algorithm can be used for signing or encryption.

### `XCN_CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG:0x80000000`

The algorithm is used for signing.

### `XCN_CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG:0x40000000`

The algorithm is used for encryption.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname)