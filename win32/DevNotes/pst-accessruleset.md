# PST\_ACCESSRULESET structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Identifies the set of access rules for the protected storage data.

## Members

**cbSize**

The size of this structure.

**cRules**

The number of rules in the **rgRules** array.

**rgRules**

A pointer to an array of [**PST\_ACCESSRULE**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessrule) structures.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

## See also

[**PST\_ACCESSRULE**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessrule)

[**CreateSubtype**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-createsubtype)

