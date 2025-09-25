# CertSetEnhancedKeyUsage function

## Description

The **CertSetEnhancedKeyUsage** function sets the [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (EKU) property for the certificate. Use of this function replaces any EKUs associated with the certificate. To add a single EKU usage without changing existing usages, use
[CertAddEnhancedKeyUsageIdentifier](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certaddenhancedkeyusageidentifier). To delete a single EKU usage, use
[CertRemoveEnhancedKeyUsageIdentifier](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certremoveenhancedkeyusageidentifier).

## Parameters

### `pCertContext` [in]

A pointer to the
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) of the specified certificate.

### `pUsage` [in]

Pointer to a [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure (equivalent to a
**CTL_USAGE** structure) that contains an array of EKU [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) to be set as extended properties of the certificate.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CertGetEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetenhancedkeyusage)

[Enhanced Key Usage Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)