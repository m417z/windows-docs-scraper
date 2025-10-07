# CAPICOM\_CERT\_INFO\_TYPE enumeration

The **CAPICOM\_CERT\_INFO\_TYPE** enumeration type defines what information is to be queried from a certificate.

## Members

| Member | Description | Value |
|------------------------------------------------|----------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_CERT\_INFO\_SUBJECT\_SIMPLE\_NAME** | Returns the display name of the certificate subject.<br> | 0 |
| **CAPICOM\_CERT\_INFO\_ISSUER\_SIMPLE\_NAME** | Returns the display name of the issuer of the certificate.<br> | 1 |
| **CAPICOM\_CERT\_INFO\_SUBJECT\_EMAIL\_NAME** | Returns the email address of the certificate subject.<br> | 2 |
| **CAPICOM\_CERT\_INFO\_ISSUER\_EMAIL\_NAME** | Returns the email address of the issuer of the certificate.<br> | 3 |
| **CAPICOM\_CERT\_INFO\_SUBJECT\_UPN** | Returns the UPN of the certificate subject. Introduced in CAPICOM 2.0.<br> | 4 |
| **CAPICOM\_CERT\_INFO\_ISSUER\_UPN** | Returns the UPN of the issuer of the certificate. Introduced in CAPICOM 2.0.<br> | 5 |
| **CAPICOM\_CERT\_INFO\_SUBJECT\_DNS\_NAME** | Returns the DNS name of the certificate subject. Introduced in CAPICOM 2.0.<br> | 6 |
| **CAPICOM\_CERT\_INFO\_ISSUER\_DNS\_NAME** | Returns the DNS name of the issuer of the certificate. Introduced in CAPICOM 2.0.<br> | 7 |

## Remarks

The **CAPICOM\_CERT\_INFO\_TYPE** enumeration type is used by the [**Certificate.GetInfo**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-getinfo) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

