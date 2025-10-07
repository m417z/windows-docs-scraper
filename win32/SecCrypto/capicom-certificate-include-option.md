# CAPICOM\_CERTIFICATE\_INCLUDE\_OPTION enumeration

The **CAPICOM\_CERTIFICATE\_INCLUDE\_OPTION** enumeration type defines which certificates in a chain are saved. This enumeration type was introduced in CAPICOM 2.0.

## Members

| Member | Description | Value |
|--------------------------------------------------------|---------------------------------------------------------------------------------------|-------|
| **CAPICOM\_CERTIFICATE\_INCLUDE\_CHAIN\_EXCEPT\_ROOT** | Saves all certificates in the chain with the exception of the root entity.<br> | 0 |
| **CAPICOM\_CERTIFICATE\_INCLUDE\_WHOLE\_CHAIN** | Saves the complete certificate chain.<br> | 1 |
| **CAPICOM\_CERTIFICATE\_INCLUDE\_END\_ENTITY\_ONLY** | Saves only the end entity certificate.<br> | 2 |

## Remarks

The **CAPICOM\_CERTIFICATE\_INCLUDE\_OPTION** enumeration type is used by the [**Certificate.Save**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-save) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

