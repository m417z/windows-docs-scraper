# NTMS_IEPORTINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_IEPORTINFORMATION** structure defines properties specific to an insert/eject port object.

## Members

### `Number`

Library port number.

### `Content`

Full/Empty state of the NTMS_IEPORT object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_PORTCONTENT_FULL** | Port is full. |
| **NTMS_PORTCONTENT_EMPTY** | Port is empty. |
| **NTMS_PORTCONTENT_UNKNOWN** | Content of port is not known. |

### `Position`

Position of the NTMS_IEPORT object. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_PORTPOSITION_EXTENDED** | Port is extended. |
| **NTMS_PORTPOSITION_RETRACTED** | Port is retracted. |
| **NTMS_PORTPOSITION_UNKNOWN** | Port position is unknown. |

### `MaxExtendSecs`

Maximum number of seconds the port is allowed to remain open before an operator request is issued. Valid values are between 0 and 65,535 seconds. This member is writable.

### `Library`

Library that contains the port.

## Remarks

The
**NTMS_IEPORTINFORMATION** structure is included in the
[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa) structure.

## See also

[NTMS_OBJECTINFORMATION](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ns-ntmsapi-ntms_objectinformationa)