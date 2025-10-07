# CAPICOM\_KEY\_STORAGE\_FLAG enumeration

The **CAPICOM\_KEY\_STORAGE\_FLAG** enumeration defines key storage flags.

## Members

| Member | Description | Value |
|--------------------------------------------|---------------------------------------|-------|
| **CAPICOM\_KEY\_STORAGE\_DEFAULT** | Default key storage.<br> | 0 |
| **CAPICOM\_KEY\_STORAGE\_EXPORTABLE** | The key is exportable.<br> | 1 |
| **CAPICOM\_KEY\_STORAGE\_USER\_PROTECTED** | The key is user protected.<br> | 2 |

## Remarks

This enumeration is used by the following method:

- [**Certificate.Load**](https://learn.microsoft.com/windows/win32/seccrypto/certificate-load)
- [**Store.Load**](https://learn.microsoft.com/windows/win32/seccrypto/store-load)

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

