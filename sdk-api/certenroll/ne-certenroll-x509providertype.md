# X509ProviderType enumeration

## Description

The **X509ProviderType** enumeration specifies the type of cryptographic provider. Providers implement cryptographic standards and algorithms in software and hardware. This enumeration is used by the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) and [IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey) interfaces.

## Constants

### `XCN_PROV_NONE:0`

No provider is identified.

### `XCN_PROV_RSA_FULL:1`

Supports the following algorithms:

* Encryption: [RC2](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) and [RC4](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly)
* Hashing: [MD5](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) and SHA
* Key Exchange: [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly)
* Signatures: RSA

### `XCN_PROV_RSA_SIG:2`

Supports the following algorithms:

* Hashing: MD5 and SHA
* Signatures: RSA

### `XCN_PROV_DSS:3`

Supports the following algorithms. This is a subset of the XCN_PROV_DSS_DH provider type.

* Hashing: MD5 and SHA
* Signatures: [Digital Signature Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSS)

### `XCN_PROV_FORTEZZA:4`

Supports the Fortezza cryptographic card developed by NSA. This includes support for the following algorithms:

* Encryption: Skipjack
* Hashing: SHA
* Key Exchange: KEA
* Signatures: DSS

### `XCN_PROV_MS_EXCHANGE:5`

Supports cryptographic algorithms used by the Microsoft Exchange mail application and other applications compatible with Microsoft Mail.
This includes the following:

* Encryption: [CAST](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)
* Hashing: MD5
* Key Exchange: RSA
* Signatures: RSA

### `XCN_PROV_SSL:6`

Supports the [Secure Sockets Layer protocol](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This includes the following algorithms:

* Encryption: variable
* Hashing: variable
* Key Exchange: RSA
* Signatures: RSA

### `XCN_PROV_RSA_SCHANNEL:12`

Supports RSA and [Schannel](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) protocols. This includes the following algorithms:

* Encryption: RC4, [Data Encryption Standard](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DES), 3DES
* Hashing: MD5, SHA
* Key Exchange: RSA
* Signatures: RSA

### `XCN_PROV_DSS_DH:13`

Supports the following algorithms:

* Encryption: [CYLINK_MEK](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)
* Hashing: MD5, SHA
* Key Exchange: [Diffie-Hellman algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly)
* Signatures: DSS

### `XCN_PROV_EC_ECDSA_SIG:14`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_EC_ECNRA_SIG:15`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_EC_ECDSA_FULL:16`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_EC_ECNRA_FULL:17`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_DH_SCHANNEL:18`

Supports the Diffie-Hellman and Schannel protocols. This includes the following algorithms:

* Encryption: DES, 3DES
* Hashing: MD5, SHA
* Key Exchange: Diffie-Hellman algorithm
* Signatures: DSS

### `XCN_PROV_SPYRUS_LYNKS:20`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_RNG:21`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_INTEL_SEC:22`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_REPLACE_OWF:23`

Microsoft currently does not provide a CSP of this type.

### `XCN_PROV_RSA_AES:24`

Supports the following algorithms:

* Encryption: RC2, RC4, [AES](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly)
* Hashing: MD5, SHA
* Key Exchange: RSA
* Signatures: RSA

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)