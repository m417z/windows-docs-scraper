# WTHelperCertFindIssuerCertificate function

\[The **WTHelperCertFindIssuerCertificate** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

The **WTHelperCertFindIssuerCertificate** function finds an issuer certificate from the specified certificate stores that matches the specified subject certificate.

> [!Note]
> This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Wintrust.dll.

## Parameters

*pChildContext* \[in\]

The subject certificate for which to find a matching issuer certificate.

*chStores* \[in\]

The number of elements in the *pahStores* array.

*pahStores* \[in\]

An array of certificate stores in which to search.

*psftVerifyAsOf* \[in\]

The time of verification.

*dwEncoding* \[in\]

A **DWORD** value that specifies the encoding types of the certificate to check. For information about possible encoding types, see [Certificate and Message Encoding Types](https://learn.microsoft.com/windows/win32/seccrypto/certificate-and-message-encoding-types).

*pdwConfidence* \[out, optional\]

This parameter can be a bitwise combination of zero or more of the following confidence values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| **CERT\_CONFIDENCE\_SIG**<br> 0x10000000 | The signature of the certificate is valid.<br> |
| **CERT\_CONFIDENCE\_TIME**<br> 0x01000000 | The time of the certificate issuer is valid.<br> |
| **CERT\_CONFIDENCE\_TIMENEST**<br>0x00100000 | The time of the certificate is valid.<br> |
| **CERT\_CONFIDENCE\_AUTHIDEXT**<br>0x00010000 | The authority ID extension is valid.<br> |
| **CERT\_CONFIDENCE\_HYGIENE**<br>0x00001000 | At a minimum, the signature of the certificate and authority ID extension are valid.<br> |
| **CERT\_CONFIDENCE\_HIGHEST**<br>0x11111000 | A combination of all of the other confidence values.<br> |

*dwError* \[out\]

A pointer to a **DWORD** variable that contains the error value for this certificate, if applicable.

## Return value

An issuer certificate that matches the subject certificate specified by the *pChildContext* parameter.

## Remarks

To successfully find a matching issuer certificate, the following requirements must be met:

- The signature of the subject certificate specified by the *pChildContext* parameter must be valid.
- The **rgExtension** member of the **pCertInfo** member of the *pChildContext* parameter must contain a [**CERT\_AUTHORITY\_KEY\_ID\_INFO**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_authority_key_id_info) structure. The **CertIssuer** and **CertSerialMember** members of this structure much match the corresponding members for the issuer certificate.
- The value of the *psftVerifyAsOf* parameter must be within the period of validity of the subject certificate.
- The period of validity of the subject certificate must be within the period of validity of the issuer certificate.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Wintrust.dll |

