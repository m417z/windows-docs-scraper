# CARD\_DIRECTORY\_ACCESS\_CONDITION enumeration

The **CARD\_DIRECTORY\_ACCESS\_CONDITION** enumeration specifies access control permissions for a directory on a [*smart card*](https://learn.microsoft.com/windows/win32/secgloss/s-gly).

## Constants

**InvalidAc**

This value is not valid.

**UserCreateDeleteDirAc**

Specific users can read, write, and delete the directory.

**AdminCreateDeleteDirAc**

Administrators can read, write, and delete the directory.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003, Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Cardmod.h |

## See also

[Microsoft Base Smart Card Cryptographic Service Provider](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/microsoft-base-smart-card-cryptographic-service-provider)

[**CardCreateDirectory**](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/cardcreatedirectory)

[**CardDeleteDirectory**](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/carddeletedirectory)

