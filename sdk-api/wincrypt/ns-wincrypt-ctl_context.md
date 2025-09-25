# CTL_CONTEXT structure

## Description

The **CTL_CONTEXT** structure contains both the encoded and decoded representations of a [CTL](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). It also contains an opened **HCRYPTMSG** handle to the decoded, cryptographically signed message containing the
[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) as its [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

CryptoAPI
[low-level message functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) can be used to extract additional signer information.

A **CTL_CONTEXT** returned by any CryptoAPI function must be freed by calling the
[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext) function.

## Members

### `dwMsgAndCertEncodingType`

Type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pbCtlEncoded`

A pointer to the encoded CTL.

### `cbCtlEncoded`

The size, in bytes, of the encoded CTL.

### `pCtlInfo`

A pointer to
[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) structure contain the CTL information.

### `hCertStore`

A handle to the certificate store.

### `hCryptMsg`

Open **HCRYPTMSG** handle to a decoded, cryptographic-signed message containing the [CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info) as its [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly).

### `pbCtlContent`

The encoded [inner content](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the signed message.

### `cbCtlContent`

Count, in bytes, of **pbCtlContent**.

## See also

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)

[CertAddCTLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddctlcontexttostore)

[CertAddEncodedCTLToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddencodedctltostore)

[CertCreateCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcreatectlcontext)

[CertEnumCTLsInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certenumctlsinstore)

[CertFindCTLInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindctlinstore)

[CertFindSubjectInCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindsubjectinctl)

[CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext)

[CryptMsgGetAndVerifySigner](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetandverifysigner)

[CryptMsgSignCTL](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgsignctl)