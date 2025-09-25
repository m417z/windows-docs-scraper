# RepairInfo structure

## Description

The **RepairInfo** structure contains data required for a particular repair option.

## Members

### `guid`

A unique GUID for this repair.

### `pwszClassName`

A pointer to a null-terminated string that contains the helper class name in a user-friendly way.

### `pwszDescription`

A pointer to a null-terminated string that describes the repair in a user friendly way.

### `sidType`

One of the WELL_KNOWN_SID_TYPE if the repair requires certain user contexts or privileges.

### `cost`

The number of seconds required to perform the repair.

### `flags`

Additional information about the repair.

| Value | Meaning |
| --- | --- |
| **RF_WORKAROUND** | Indicates that the repair is a workaround for the issue. For example, sometimes resetting a network interface solves intermittent problems, but does not directly address a specific issue, so it is considered a workaround. NDF will show non-workarounds to the user before workarounds. |
| **RF_USER_ACTION** | Indicates that the repair prompts the user to perform a manual task outside of NDF. |
| **RF_USER_CONFIRMATION** | Indicates that the repair should not be automatically performed. The user is instead prompted to select the repair. |
| **RF_INFORMATION_ONLY** | Indicates that the repair consists of actionable information for the user. Repair and validation sessions do not occur for information-only repairs. |
| **RF_VALIDATE_HELPTOPIC** | Indicates that the repair provides information to the user as well as a help topic. Unlike **RF_INFORMATION_ONLY** repairs, which cannot be validated, this repair can be executed and validated within a diagnostic session.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |
| **RF_REPRO** | Indicates that the repair prompts the user to reproduce their problem. At the same time, the helper class may have enabled more detailed logging or other background mechanisms to help detect the failure.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |
| **RF_CONTACT_ADMIN** | Indicates that the repair prompts the user to contact their network administrator in order to resolve the problem.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |
| **RF_RESERVED** | Reserved for system use.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |
| **RF_RESERVED_CA** | Reserved for system use.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |
| **RF_RESERVED_LNI** | Reserved for system use.<br><br>**Note** Available only in Windows 7, Windows Server 2008 R2, and later. |

### `scope`

Reserved for future use.

### `risk`

Reserved for future use.

### `UiInfo`

A [UiInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-uiinfo) structure.

### `rootCauseIndex`

## See also

[CopyRepairInfo](https://learn.microsoft.com/windows/desktop/NDF/copyrepairinfo)

[FreeRepairInfos](https://learn.microsoft.com/windows/desktop/NDF/freerepairinfos)

[UiInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-uiinfo)