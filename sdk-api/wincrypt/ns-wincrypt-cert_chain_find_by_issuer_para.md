# CERT_CHAIN_FIND_BY_ISSUER_PARA structure

## Description

The **CERT_CHAIN_FIND_BY_ISSUER_PARA** structure contains information used in the [CertFindChainInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindchaininstore) function to build certificate chains.

## Members

### `cbSize`

Contains the size of this structure, in bytes. This size should not be hard-coded. It should be set at compile time by using the **sizeof** operator as shown in the following example.

```cpp
CERT_CHAIN_FIND_BY_ISSUER_PARA findParams;
findParams.cbSize = sizeof(CERT_CHAIN_FIND_BY_ISSUER_PARA);
```

### `pszUsageIdentifier`

A pointer to a null-terminated ANSI string that contains the usage identifier to be matched. If this member is **NULL**, a certificate with any usage can be a match.

### `dwKeySpec`

Contains the key specification value to be matched. This can be one of the following values. If this parameter is zero, any certificate can match.

| Value | Meaning |
| --- | --- |
| **AT_KEYEXCHANGE**<br><br>0x01 | The key can be used to encrypt or sign depending on the algorithm. |
| **AT_SIGNATURE**<br><br>0x02 | The key can be used for signing. |

### `dwAcquirePrivateKeyFlags`

When the *dwFindFlags* parameter of the [CertFindChainInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindchaininstore) function contains **CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG**, the [CryptAcquireCertificatePrivateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecertificateprivatekey) function is called to do the public key comparison. In this case, this member is passed as the *dwFlags* parameter of the **CryptAcquireCertificatePrivateKey** function. For possible values for this member and their meanings, see the *dwFlags* parameter of the **CryptAcquireCertificatePrivateKey** function.

### `cIssuer`

Contains the number of elements in the **rgIssuer** array. If this member is zero, any issuer can be a match.

### `rgIssuer`

An array of [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly), [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded issuer name [BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) to match. If this member is **NULL** or the callback function returns **TRUE**, a new element is added to the chain for the certificate having a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) with the specified KeySpec and [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly).

### `pfnFindCallback`

A pointer to a [CertChainFindByIssuerCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_chain_find_by_issuer_callback) callback function that allows the application to filter the certificates that chains are created for. If this member is **NULL**, a chain is built for every certificate found. If this member is not **NULL**, a chain will be built for the certificate found based on the return value of the callback function.

### `pvFindArg`

An application-defined value that will be passed as the *pvFindArg* parameter of the [CertChainFindByIssuerCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_chain_find_by_issuer_callback) callback function pointed to by the **pfnFindCallback** member of this structure.

### `pdwIssuerChainIndex`

A pointer to a **DWORD** value that receives the zero-based index of the chain that matches the issuer. If this member is **NULL**, it is not used.

If **cIssuer** is zero, this member is not used.

This member is only defined if the **CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS** macro is defined.

### `pdwIssuerElementIndex`

A pointer to a **DWORD** value that receives the zero-based index of the element in the chain of the certificate of the issuer. If this member is **NULL**, it is not used.

If **cIssuer** is zero, this member is not used.

This member is set to the index of the found certificate plus one to provide the index of the certificate of the issuer. Because of this, a partial chain or a self-signed certificate that matches the name BLOB may cause **pdwIssuerElementIndex** to point past the last certificate in the chain. This situation can be detected by comparing the contents of **pdwIssuerElementIndex** with the **cElement** member of the [CERT_SIMPLE_CHAIN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_simple_chain) structure to make sure the index is valid.

This member is only defined if the **CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS** macro is defined.

## Remarks

The **pdwIssuerChainIndex** and **pdwIssuerElementIndex** members are only available if the **CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS** macro is defined. If the **CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS** macro is defined, the application must initialize all unused fields to zero.

#### Examples

The following pseudocode shows how to use the **pdwIssuerChainIndex** and **pdwIssuerElementIndex** members of this structure to access the certificate of the issuer.

```cpp
CERT_CHAIN_FIND_BY_ISSUER_PARA findParams;
PCCERT_CHAIN_CONTEXT pChainContext = NULL;
DWORD dwChainIndex = 0;
DWORD dwElementIndex = 0;
findParams.pdwIssuerChainIndex = &dwChainIndex;
findParams.pdwIssuerElementIndex = &dwElementIndex;

pChainContext = CertFindChainInStore(
    hCertStore,
    X509_ASN_ENCODING,
    0,
    CERT_CHAIN_FIND_BY_ISSUER,
    (LPVOID)&findParams,
    NULL);
if(pChainContext)
{
    // Make sure the element index is valid.
    if(dwElementIndex < pChainContext->
        rgpChain[dwChainIndex]->cElement)
    {
        PCERT_CHAIN_ELEMENT pIssuerElement;
        pIssuerElement = pChainContext->
            rgpChain[dwChainIndex]->rgpElement[dwElementIndex];
       // ...
    }

    // Free the certificate chain.
    CertFreeCertificateChain(pChainContext);
}
```

## See also

[CertChainFindByIssuerCallback](https://learn.microsoft.com/windows/desktop/api/wincrypt/nc-wincrypt-pfn_cert_chain_find_by_issuer_callback)

[CertFindChainInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindchaininstore)

[CryptAcquireCertificatePrivateKey](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecertificateprivatekey)