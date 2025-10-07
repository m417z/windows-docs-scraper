# CAPICOM\_EXPORT\_FLAG enumeration

The **CAPICOM\_EXPORT\_FLAG** enumeration type defines whether any private key export errors are ignored.

## Members

| Member | Description | Value |
|-------------------------------------------------------------------|-----------------------------------------------------------|-------|
| **CAPICOM\_EXPORT\_DEFAULT** | Any private key export errors are not ignored.<br> | 0 |
| **CAPICOM\_EXPORT\_IGNORE\_PRIVATE\_KEY\_NOT\_EXPORTABLE\_ERROR** | Any private key export errors are ignored.<br> | 1 |

## Remarks

The CAPICOM\_EXPORT\_FLAG enumeration type is used by the following method:

- [**Certificates.Save**](https://learn.microsoft.com/windows/win32/seccrypto/certificates-save)

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

