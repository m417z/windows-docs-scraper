# CARD\_FILE\_ACCESS\_CONDITION enumeration

The **CARD\_FILE\_ACCESS\_CONDITION** enumeration specifies access control permissions for a file on a [*smart card*](https://learn.microsoft.com/windows/win32/secgloss/s-gly).

## Constants

**InvalidAc**

This value is not valid.

**EveryoneReadUserWriteAc**

Everyone can read the file. Specific users can write to the file.

**UserWriteExecuteAc**

Only specific users can read or write to the file.

**EveryoneReadAdminWriteAc**

Everyone can read the file. Administrators can write to the file.

**UnknownAc**

Access permissions for the file are unknown.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003, Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Cardmod.h |

## See also

[Microsoft Base Smart Card Cryptographic Service Provider](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/microsoft-base-smart-card-cryptographic-service-provider)

[**CARD\_FILE\_INFO**](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/card-file-info)

[**CardCreateFile**](https://learn.microsoft.com/previous-versions/windows/desktop/secsmart/cardcreatefile)

