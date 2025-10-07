# CAPICOM\_STORE\_OPEN\_MODE enumeration

The CAPICOM\_STORE\_OPEN\_MODE enumeration type is used with the [**Store.Open**](https://learn.microsoft.com/windows/win32/seccrypto/store-open) method to indicate how a certificate store is to be opened.

## Members

| Member | Description | Value |
|---------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_STORE\_OPEN\_READ\_ONLY** | Open the store in read-only mode.<br> | 0 |
| **CAPICOM\_STORE\_OPEN\_READ\_WRITE** | Open the store in read/write mode.<br> | 1 |
| **CAPICOM\_STORE\_OPEN\_MAXIMUM\_ALLOWED** | Open the store in read/write mode if the user has read/write permissions. If the user does not have read/write permissions, open the store in read-only mode.<br> | 2 |
| **CAPICOM\_STORE\_OPEN\_EXISTING\_ONLY** | Open existing stores only; do not create a new store. Introduced by CAPICOM 2.0.<br> | 128 |
| **CAPICOM\_STORE\_OPEN\_INCLUDE\_ARCHIVED** | Include archived certificates when using the store. Introduced by CAPICOM 2.0.<br> | 256 |

## Remarks

When using the CAPICOM\_STORE\_OPEN\_MODE enumeration, only one of the following settings can be used.

- CAPICOM\_STORE\_OPEN\_READ\_ONLY
- CAPICOM\_STORE\_OPEN\_READ\_WRITE
- CAPICOM\_STORE\_OPEN\_MAXIMUM\_ALLOWED

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

## See also

[**Store.Open**](https://learn.microsoft.com/windows/win32/seccrypto/store-open)

