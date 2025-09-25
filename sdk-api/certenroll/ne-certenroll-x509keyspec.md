# X509KeySpec enumeration

## Description

The **X509KeySpec** enumeration type specifies the intended use of a key for a legacy [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). Legacy CSPs can support at most one signature algorithm (XCN_AT_SIGNATURE) and one encryption algorithm (XCN_AT_KEYEXCHANGE). This enumeration is used by the following interfaces:

* [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)
* [ICspInformations](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformations)
* [IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider)
* [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10)
* [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)

## Constants

### `XCN_AT_NONE:0`

The intended use is not identified. This value is set if the provider that supports the key is a Cryptography API: Next Generation (CNG) key storage provider (KSP).

### `XCN_AT_KEYEXCHANGE:1`

The key can be used to encrypt (including key exchange) or sign depending on the algorithm. For RSA algorithms, if this value is set, the key can be used for both signing and encryption. For other algorithms, signing may not be supported. Further, only encryption for key exchange may be supported.

**Note** The KEYEXCHANGE portion of the value name is a carryover from CryptoAPI where it originally referred to the symmetric encryption of a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used during key exchange. Use of the term ultimately expanded to cover all symmetric encryption.

### `XCN_AT_SIGNATURE:2`

The key can be used for signing.

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)