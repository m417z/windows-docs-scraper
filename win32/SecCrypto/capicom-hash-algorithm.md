# CAPICOM\_HASH\_ALGORITHM enumeration

The **CAPICOM\_HASH\_ALGORITHM** enumeration defines a hash algorithm.

## Members

| Member | Description | Value |
|----------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_HASH\_ALGORITHM\_SHA1** | [*Secure Hash Algorithm*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SHA) that generates a 160-bit message digest.<br> | 0 |
| **CAPICOM\_HASH\_ALGORITHM\_MD2** | MD2 hashing algorithm.<br> | 1 |
| **CAPICOM\_HASH\_ALGORITHM\_MD4** | MD4 hashing algorithm.<br> | 2 |
| **CAPICOM\_HASH\_ALGORITHM\_MD5** | MD5 hashing algorithm.<br> | 3 |
| **CAPICOM\_HASH\_ALGORITHM\_SHA\_256** | SHA-256 hash algorithm.<br> **CAPICOM 2.0.0.3 and earlier:** This value is not supported.<br> | 4 |
| **CAPICOM\_HASH\_ALGORITHM\_SHA\_384** | SHA-384 hash algorithm.<br> **CAPICOM 2.0.0.3 and earlier:** This value is not supported.<br> | 5 |
| **CAPICOM\_HASH\_ALGORITHM\_SHA\_512** | SHA-512 hash algorithm.<br> **CAPICOM 2.0.0.3 and earlier:** This value is not supported.<br> | 6 |

## Remarks

The **CAPICOM\_HASH\_ALGORITHM** enumeration is used by the [**HashedData.Algorithm**](https://learn.microsoft.com/windows/win32/seccrypto/hasheddata-algorithm) property.

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

