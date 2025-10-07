# PST\_ACCESSCLAUSE structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Contains information about the access clause for the protected storage.

## Members

**cbSize**

The size of this structure.

**ClauseType**

The type of data that is pointed to by the **pbClauseData** member. For more information, see [**PStore Types**](https://learn.microsoft.com/windows/win32/devnotes/pstore-types).

**cbClauseData**

The size of the data that is pointed to by the **pbClauseData** member.

**pbClauseData**

A pointer to the access clause data.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

## See also

[**PST\_ACCESSRULE**](https://learn.microsoft.com/windows/win32/devnotes/pst-accessrule)

