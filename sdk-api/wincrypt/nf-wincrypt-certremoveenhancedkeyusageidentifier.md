# CertRemoveEnhancedKeyUsageIdentifier function

## Description

The **CertRemoveEnhancedKeyUsageIdentifier** function removes a usage identifier [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) from the [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (EKU) extended property of the certificate.

## Parameters

### `pCertContext` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the certificate for which the usage identifier OID is to be removed.

### `pszUsageIdentifier` [in]

A pointer to the usage identifier OID to remove.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Enhanced Key Usage Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)