# CertFindChainInStore function

## Description

The **CertFindChainInStore** function finds the first or next certificate in a [store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that meets the specified criteria. It then builds and verifies a certificate chain context for that certificate. The certificate that is found and for which the chain is built is selected according to criteria established by the *dwFindFlags*, *dwFindType*, and *pvFindPara* parameters. This function can be used in a loop to find all of the certificates in a certificate store that match the specified find criteria and to build a certificate chain context for each certificate found.

## Parameters

### `hCertStore` [in]

The handle of the store to be searched for a certificate upon which a chain is built. This handle is passed as an additional store to
the [CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain) function as the chain is built.

### `dwCertEncodingType` [in]

The [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that was used to encode the store. The [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) identifier, contained in the high **WORD** of this value, is ignored by this function.

This parameter can be the following currently defined certificate encoding type.

| Value | Meaning |
| --- | --- |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `dwFindFlags` [in]

Contains additional options for the search. The possible values for this parameter depend on the value of the *dwFindType* parameter.

This parameter can contain zero or a combination of one or more of the following values when *dwFindType* contains **CERT_CHAIN_FIND_BY_ISSUER**.

| Value | Meaning |
| --- | --- |
| **CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG** | Compares the public key in the certificate with the [cryptographic service provider's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This comparison is the last check made on the chain when it is built.<br><br>Because the **hCryptProv** member of an issuer contains a private key, it might need to be checked several times during this process; to facilitate this checking, the *dwAcquirePrivateKeyFlags* member can be set in the [CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para) structure to enable caching of that **hCryptProv**. |
| **CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG** | By default, only the first simple chain is checked for issuer name matches. With this flag set, the default is overridden and subsequent simple chains are also checked for issuer name matches. |
| **CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG** | Improves the performance of this function by causing it to search only the cached system stores (Root, My, Ca, Trust) to find issuer certificates. If this flag is not set, the function searches the cached system stores and the store represented by the *hCertStore* parameter. |
| **CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG** | Only the URL cache is searched. The Internet is not searched. |
| **CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG** | Only opens the Local Machine certificate stores. The certificate stores of the current user are not opened. |
| **CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG** | No check is made to determine whether the certificate has an associated private key. |

### `dwFindType` [in]

Determines what criteria to use to find a certificate in the store.

This parameter can be the following currently defined value.

#### CERT_CHAIN_FIND_BY_ISSUER

Finds the certificate based on the name of the issuer. The *pvFindPara* parameter is a pointer to a
[CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para) structure that contains members that modify the search.

The certificate chain is built for a certificate with an available [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). By default, only the issuers in the first simple chain are compared in an issuer name match. If this flag is set, all of the chains are checked for an issuer certificate that matches one of a set of issuer names.

This function will compare the name [BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) passed in the *pvFindPara* structure to any [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) in the chain, not just the certification authority in the root certificate.

This function does not perform any revocation checks.

If *pPrevChainContext* is not **NULL**, this function will return a chain for a different certificate every time the function is called. If there is only one suitable certificate, but there are two matching issuing certificate authorities, one of which is revoked, it is possible for this function to return the revoked chain. If the application then checks for revocation itself through calls to the [CertVerifyRevocation](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyrevocation) function and finds the chain unsuitable, an additional call to the **CertFindChainInStore** function will not return a chain that includes the same certificate from the valid certification authority. It will instead return a completely different chain with a different certificate or **NULL**, if no such chain can be found.

### `pvFindPara` [in]

A pointer that contains additional search criteria. The type and format of the data this parameter points to depends on the value of the *dwFindType* parameter.

### `pPrevChainContext` [in]

A pointer to a
[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure returned from a previous call to this function. The search is begun from this certificate. For the first call to this function, this parameter must be **NULL**. In subsequent calls, it is the pointer returned by the previous call to the function. If this parameter is not **NULL**, this function will free this structure.

## Return value

If the first or next chain context is not built, **NULL** is returned. Otherwise, a pointer to a read-only [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure is returned. The **CERT_CHAIN_CONTEXT** structure is freed when passed as the *pPrevChainContext* parameter on a subsequent call to this function. Otherwise, the **CERT_CHAIN_CONTEXT** structure must be freed explicitly by calling
the [CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain) function.

## Remarks

The *pPrevChainContext* parameter must be **NULL** on the first call to build the chain context. To build the next chain context, the *pPrevChainContext* is set to the [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure returned by a previous call. If *pPrevChainContext* is not **NULL**, the structure is always freed by this function by using the [CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain) function, even if an error occurs.

## See also

[CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context)

[CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para)

[CertFreeCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatechain)

[CertGetCertificateChain](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatechain)

[Certificate Chain Verification Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)