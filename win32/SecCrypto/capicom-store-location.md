# CAPICOM\_STORE\_LOCATION enumeration

The **CAPICOM\_STORE\_LOCATION** enumeration type indicates the location of a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

## Members

| Member | Description | Value |
|---------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------|
| **CAPICOM\_MEMORY\_STORE** | The store is a memory store. Any changes in the contents of the store are not persisted.<br> | 0 |
| **CAPICOM\_LOCAL\_MACHINE\_STORE** | The store is a local machine store. Local machine stores can be read/write stores only if the user has read/write permissions. If the user has read/write permissions and if the store is opened read/write, then changes in the contents of the store are persisted.<br> | 1 |
| **CAPICOM\_CURRENT\_USER\_STORE** | The store is a current user store. A current user store may be a read/write store. If it is, changes in the contents of the store are persisted.<br> | 2 |
| **CAPICOM\_ACTIVE\_DIRECTORY\_USER\_STORE** | The store is an Active Directory store. Active Directory stores can be opened only in read-only mode. Certificates cannot be added to or removed from Active Directory stores.<br> | 3 |
| **CAPICOM\_SMART\_CARD\_USER\_STORE** | Stores support smart card–based certificate stores. The store is the group of present smart cards. Introduced in CAPICOM 2.0.<br> | 4 |

## Remarks

The **CAPICOM\_STORE\_LOCATION** enumeration type is used by the following methods:

- [**PrivateKey.Open**](https://learn.microsoft.com/windows/win32/seccrypto/privatekey-open)
- [**Store.Open**](https://learn.microsoft.com/windows/win32/seccrypto/store-open)

## Requirements

| Requirement | Value |
|----------------------------|--------------------------------------------------------------------------------------|
| Redistributable<br> | CAPICOM 2.0 or later on Windows Server 2003 and Windows XP<br> |
| Header<br> | Capicom.h |

