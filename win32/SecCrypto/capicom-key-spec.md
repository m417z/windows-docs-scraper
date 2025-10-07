# CAPICOM\_KEY\_SPEC enumeration

The **CAPICOM\_KEY\_SPEC** enumeration defines key specifications.

## Members

| Member | Description | Value |
|-------------------------------------|------------------------------------------------------------|-------|
| **CAPICOM\_KEY\_SPEC\_KEYEXCHANGE** | The key can be used for encryption and signing.<br> | 1 |
| **CAPICOM\_KEY\_SPEC\_SIGNATURE** | The key can be used only for signing.<br> | 2 |

## Remarks

The **CAPICOM\_KEY\_SPEC** enumeration is used by the following methods and properties:

- [**PrivateKey.KeySpec**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey-keyspec) property.
- [**PrivateKey.Open**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey-open) method.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

