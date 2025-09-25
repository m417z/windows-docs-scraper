# NTMS_STORAGESLOTINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_STORAGESLOTINFORMATION** structure defines properties specific to a storage slot object.

## Members

### `Number`

Number of the slot in the library.

### `State`

Current state of the slot. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_SLOTSTATE_EMPTY** | Slot is present, but does not contain a piece of physical media. |
| **NTMS_SLOTSTATE_FULL** | Slot is present and contains a piece of physical media. |
| **NTMS_SLOTSTATE_NOTPRESENT** | Slot is not present. If the library contains magazines, this value is reported for each slot when the associated magazine is missing. |
| **NTMS_SLOTSTATE_UNKNOWN** | Slot state cannot be determined. |
| **NTMS_SLOTSTATE_NEEDSINVENTORY** | Slot needs inventory. |

### `Library`

Library that contains the slot.

## Remarks

The
**NTMS_STORAGESLOTINFORMATION** structure is part of the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)