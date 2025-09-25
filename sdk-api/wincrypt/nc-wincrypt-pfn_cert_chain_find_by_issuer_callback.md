# PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK callback function

## Description

The **CertChainFindByIssuerCallback** function is an application-defined callback function that allows the application to filter certificates that might be added to the certificate chain. A pointer to this function is provided in the **pfnFindCallback** member of the [CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para) structure.

## Parameters

### `pCert` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains the certificate in question.

### `pvFindArg` [in]

A pointer to an application-defined value. This is the same value that was passed in the *pvFindArg* member of the [CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para) structure.

## Return value

Return **TRUE** to create a chain for the certificate specified in the *pCert* parameter, or **FALSE** otherwise.

## See also

[CERT_CHAIN_FIND_BY_ISSUER_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_find_by_issuer_para)

[CertFindChainInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindchaininstore)