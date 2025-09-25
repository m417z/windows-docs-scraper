# CertFindCRLInStore function

## Description

The **CertFindCRLInStore** function finds the first or next [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) context in a [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) that matches a search criterion established by the *dwFindType* parameter and the associated *pvFindPara* parameter. This function can be used in a loop to find all of the CRL contexts in a certificate store that match the specified find criteria.

## Parameters

### `hCertStore` [in]

A handle of the certificate store to be searched.

### `dwCertEncodingType` [in]

This parameter is not currently used. It must be set to zero.

### `dwFindFlags` [in]

If *dwFindType* is CRL_FIND_ISSUED_BY, by default, only issuer name matching is done. The following flags can be used to do additional filtering.

| Value | Meaning |
| --- | --- |
| **CRL_FIND_ISSUED_BY_AKI_FLAG** | Checks for a CRL that has an Authority Key Identifier (AKI) extension. If the CRL has an AKI, only a CRL whose AKI matches the issuer is returned.<br><br>**Note** The AKI extension has the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) value szOID_AUTHORITY_KEY_IDENTIFIER2 and its corresponding data structure. |
| **CRL_FIND_ISSUED_BY_SIGNATURE_FLAG** | Use the public key in the issuer's certificate to verify the signature on the CRL. Only returns a CRL that has a valid signature. |
| **CRL_FIND_ISSUED_BY_DELTA_FLAG** | Finds and returns a delta CRL. |
| **CRL_FIND_ISSUED_BY_BASE_FLAG** | Finds and returns a base CRL. |
| **CRL_FIND_ISSUED_FOR_SET_STRONG_PROPERTIES_FLAG** | The signature is checked for strength after successful verification. This flag applies only when the *dwFindType* parameter is set to **CRL_FIND_ISSUED_FOR**. You must also set **CRL_FIND_ISSUED_BY_SIGNATURE_FLAG**. If successful, the following strong signature properties will be set on the CRL context:<br><br>* **CERT_SIGN_HASH_CNG_ALG_PROP_ID**<br>* **CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID**<br><br>**Windows 8 and Windows Server 2012:** Support for this flag begins. |

### `dwFindType` [in]

Specifies the type of search being made. The value of *dwFindType* determines the data type, contents, and use of the *pvFindPara* parameter. Currently defined search types and their *pvFindPara* requirements are as follows.

| Value | Meaning |
| --- | --- |
| **CRL_FIND_ANY**<br><br>The *pvFindPara* parameter is not used. It must be set to **NULL**. | No search criteria. The next CRL in the store is returned. |
| **CRL_FIND_ISSUED_BY**<br><br>A pointer to a CERT_CONTEXT. | Searches for the next CRL in the store matching the issuer in the [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context). |
| **CRL_FIND_EXISTING**<br><br>A pointer to a CRL_CONTEXT. | Searches for the next CRL that matches the [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) in the following ways:<br><br>* Both are base or delta CRLs.<br>* The issuer-name BLOBs for both are identical.<br>* If they exist, the Authority/KeyIdentifier and IssuingDistributionPoint encoded extension BLOBs match. |
| **CRL_FIND_ISSUED_FOR**<br><br>A pointer to a CRL_FIND_ISSUED_FOR_PARA. | Searches for the next CRL in the store that matches the issuer of the subject certificate in the CRL_FIND_ISSUED_FOR_PARA structure.<br><br>If no CRL is found, searches for the next CRL in the store that matches the issuer in the CRL_FIND_ISSUED_FOR_PARA structure.<br><br>**Note** When using cross certificates, the subject name in the issuer's certificate might not match the issuer name in the subject certificate and its corresponding CRL. |

### `pvFindPara` [in]

This parameter is determined by the value of *dwFindType*. For details, see the table earlier in this topic.

### `pPrevCrlContext` [in]

A pointer to the last
[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) returned by this function. Must be **NULL** to get the first CRL in the store meeting the search criteria. Successive CRLs meeting the search criteria can be found by setting *pPrevCrlContext* to the **PCCRL_CONTEXT** pointer returned by a previous call to the function. The search process skips any CRLs that do not match the search criteria or that have been previously deleted from the store by
[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore). This function frees the **CRL_CONTEXT** referenced by values of this parameter that are not **NULL**.

## Return value

If the function succeeds, the function returns a pointer to a read-only CRL context. When you have finished using the returned CRL context, free it by calling
the [CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) function or implicitly free it by passing it as the *pPrevCrlContext* parameter on a subsequent call to the **CertFindCRLInStore** function.

If the function fails and a CRL that matches the search criteria is not found, the return value is **NULL**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Some possible error codes follow.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The handle in the *hCertStore* parameter is not the same as that in the CRL context pointed to by the *pPrevCrlContext* parameter, or a search type that is not valid was specified in the *dwFindType* parameter. |
| **CRYPT_E_NOT_FOUND** | No CRLs are in the store, no CRL was found that matched the search criteria, or the end of the store's list was reached. |

## Remarks

The returned pointer is freed when passed as the *pPrevCrlContext* parameter on a subsequent call to the function. Otherwise, the pointer must be explicitly freed by calling
[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext). A *pPrevCrlContext* that is not **NULL** is always freed by **CertFindCRLInStore** using a call to **CertFreeCRLContext**, even if there is an error in the function.

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext) can be called to make a duplicate of the returned context. The returned CRL context can be added to a different certificate store by using
[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore), or a link to that CRL context can be added to a noncollection store by using
[CertAddCRLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrllinktostore).

## See also

[CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context)

[CertAddCRLContextToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrlcontexttostore)

[CertAddCRLLinkToStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddcrllinktostore)

[CertDeleteCRLFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certdeletecrlfromstore)

[CertDuplicateCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certduplicatecrlcontext)

[CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext)

[Certificate Revocation List Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)