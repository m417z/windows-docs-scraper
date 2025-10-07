# PST\_TYPEINFO structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Describes a type or a subtype.

## Members

**cbSize**

The size of this structure.

**szDisplayName**

A pointer to a wide character string that represents the display name for the type.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

## See also

[**CreateSubtype**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-createsubtype)

[**CreateType**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-createtype)

[**GetSubtypeInfo**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-getsubtypeinfo)

[**GetTypeInfo**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-gettypeinfo)

