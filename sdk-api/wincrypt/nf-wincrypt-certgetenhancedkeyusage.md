# CertGetEnhancedKeyUsage function

## Description

The **CertGetEnhancedKeyUsage** function returns information from the [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) (EKU) extension or the EKU extended property of a certificate. EKUs indicate valid uses of the certificate.

## Parameters

### `pCertContext` [in]

A pointer to a
[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) certificate context.

### `dwFlags` [in]

Indicates whether the function will report on extensions of a certificate, its extended properties, or both. If set to zero, the function returns the valid uses of a certificate based on both the EKU extension and the EKU extended property value of the certificate.

To return only the EKU extension or EKU property value, set the following flags.

| Value | Meaning |
| --- | --- |
| **CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG** | Get only the extension. |
| **CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG** | Get only the extended property value. |

### `pUsage` [out]

A pointer to a [CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure (**CERT_ENHKEY_USAGE** is an alternate typedef name for the **CTL_USAGE** structure) that receives the valid uses of the certificate.

This parameter can be **NULL** to set the size of the key usage for memory allocation purposes. For more information, see
[Retrieving Data of Unknown Length](https://learn.microsoft.com/windows/desktop/SecCrypto/retrieving-data-of-unknown-length).

### `pcbUsage` [in, out]

A pointer to a **DWORD** that specifies the size, in bytes, of the structure pointed to by *pUsage*. When the function returns, the **DWORD** contains the size, in bytes, of the structure.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## Remarks

If a certificate has an EKU extension, that extension lists [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) for valid uses of that certificate. In a Microsoft environment, a certificate might also have EKU extended properties that specify valid uses for the certificate.

* If a certificate has neither an EKU extension nor EKU extended properties, it is assumed to be valid for all uses.
* If it has either an EKU extension or EKU extended properties but not both, it is valid only for the uses indicated in the extension or extended properties that it has.
* If a certificate has both an EKU extension and EKU extended properties, it is valid only for the uses that are on both lists.

If *dwFlags* is set to zero, the **cUsageIdentifier** member of the **CERT_ENHKEY_USAGE** structure is set to the number of valid uses of the certificate determined by the value of both the EKU extension and the EKU extended property value.

If the **cUsageIdentifier** member is zero, the certificate might be valid for all uses or the certificate might have no valid uses. The return from a call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can be used to determine whether the certificate is good for all uses or for none. If **GetLastError** returns CRYPT_E_NOT_FOUND, the certificate is good for all uses. If it returns zero, the certificate has no valid uses.

## See also

[CertSetEnhancedKeyUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certsetenhancedkeyusage)

[Enhanced Key Usage Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)