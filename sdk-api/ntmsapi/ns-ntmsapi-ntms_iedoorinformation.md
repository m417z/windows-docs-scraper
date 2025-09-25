# NTMS_IEDOORINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_IEDOORINFORMATION** structure defines properties specific to an insert/eject door object.

## Members

### `Number`

Number of the door in the library. Typically, libraries have one door.

### `State`

State of the door. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_DOORSTATE_CLOSED** | Library door is closed. |
| **NTMS_DOORSTATE_OPEN** | Library door is open. |
| **NTMS_DOORSTATE_UNKNOWN** | State of the library is unknown. |

### `MaxOpenSecs`

Maximum number of seconds the door is to remain open. Valid values are between 0-65,535 seconds This member is writable.

### `Library`

Library that contains this door.

## Remarks

The
**NTMS_IEDOORINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

If the **MaxOpenSecs** member is zero, an operator request to close the door is generated as soon as the door is open.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)