# CAPICOM\_ENCRYPTION\_ALGORITHM enumeration

The **CAPICOM\_ENCRYPTION\_ALGORITHM** enumeration type defines the algorithms to be used in encryption and decryption.

## Members

| Member | Description | Value |
|------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------|
| **CAPICOM\_ENCRYPTION\_ALGORITHM\_RC2** | Use RSA RC2 encryption.<br> | 0 |
| **CAPICOM\_ENCRYPTION\_ALGORITHM\_RC4** | Use RSA RC4 encryption.<br> | 1 |
| **CAPICOM\_ENCRYPTION\_ALGORITHM\_DES** | Use DES encryption.<br> | 2 |
| **CAPICOM\_ENCRYPTION\_ALGORITHM\_3DES** | Use triple DES encryption.<br> | 3 |
| **CAPICOM\_ENCRYPTION\_ALGORITHM\_AES** | Use the [*Advanced Encryption Standard*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) (AES) algorithm. This value is valid for the [**EncryptedData**](https://learn.microsoft.com/windows/win32/seccrypto/encrypteddata) object only.<br> | 4 // v2.0 |

## Remarks

The **CAPICOM\_ENCRYPTION\_ALGORITHM** enumeration type is used by the [**Algorithm.Name**](https://learn.microsoft.com/windows/win32/seccrypto/algorithm-name) property.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

