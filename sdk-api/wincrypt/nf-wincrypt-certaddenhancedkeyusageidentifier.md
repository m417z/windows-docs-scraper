# CertAddEnhancedKeyUsageIdentifier function

## Description

The **CertAddEnhancedKeyUsageIdentifier** function adds a usage identifier [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) to the [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (EKU) extended property of the certificate.

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the certificate for which the usage identifier is to be added.

### `pszUsageIdentifier` [in]

Specifies the usage identifier OID to add.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[Enhanced Key Usage Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)