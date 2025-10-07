# CAPICOM\_ENCRYPTION\_KEY\_LENGTH enumeration

The **CAPICOM\_ENCRYPTION\_KEY\_LENGTH** enumeration type defines the [*key length*](https://learn.microsoft.com/windows/win32/secgloss/k-gly) to be used in encryption.

## Members

| Member | Description | Value |
|-------------------------------------------------|-------------------------------------------------------------------------------------------|-----------|
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_MAXIMUM** | Uses the maximum key length available with the indicated encryption algorithm.<br> | 0 |
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_40\_BITS** | Uses 40-bit keys.<br> | 1 |
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_56\_BITS** | Uses 56-bit keys if available.<br> | 2 |
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_128\_BITS** | Uses 128-bit keys if available.<br> | 3 |
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_192\_BITS** | Uses 192-bit keys. This key length is available only for AES.<br> | 4 // v2.0 |
| **CAPICOM\_ENCRYPTION\_KEY\_LENGTH\_256\_BITS** | Uses 256-bit keys. This key length is available only for AES.<br> | 5 // v2.0 |

## Remarks

The **CAPICOM\_ENCRYPTION\_KEY\_LENGTH** enumeration type is used by the [**Algorithm.KeyLength**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-keylength) property.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

