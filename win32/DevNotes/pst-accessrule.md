# PST\_ACCESSRULE structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Describes a rule for access to items stored in protected storage.

## Members

**cbSize**

The size of this structure.

**AccessModeFlags**

The access modes to which a specified set of access clauses pertain.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------|
| **PST\_READ**<br>0x0001 | Read access mode.<br> |
| **PST\_WRITE**<br>0x0002 | Write access mode.<br> |

**cClauses**

The number of structures in the **rgClauses** array.

**rgClauses**

A pointer to an array of [**PST\_ACCESSCLAUSE**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessclause) structures.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

## See also

[**PST\_ACCESSCLAUSE**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessclause)

[**PST\_ACCESSRULESET**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessruleset)

