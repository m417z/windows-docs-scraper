# NtmsObjectsTypes enumeration

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NtmsObjectsTypes** enumeration type specifies the types of RSM objects.

## Constants

### `NTMS_UNKNOWN:0`

Unknown object.

### `NTMS_OBJECT`

Used internally when initializing an object.

### `NTMS_CHANGER`

Changer.

### `NTMS_CHANGER_TYPE`

Changer type.

### `NTMS_COMPUTER`

Computer.

### `NTMS_DRIVE`

Drive.

### `NTMS_DRIVE_TYPE`

Drive type.

### `NTMS_IEDOOR`

Insert/eject door.

### `NTMS_IEPORT`

Insert/eject port.

### `NTMS_LIBRARY`

Library (including the offline library).

### `NTMS_LIBREQUEST`

Library request.

### `NTMS_LOGICAL_MEDIA`

Logical media.

### `NTMS_MEDIA_POOL`

Media pool.

### `NTMS_MEDIA_TYPE`

Media type.

### `NTMS_PARTITION`

Side of a piece of physical media.

### `NTMS_PHYSICAL_MEDIA`

Physical media.

### `NTMS_STORAGESLOT`

Storage slot.

### `NTMS_OPREQUEST`

Operator request.

### `NTMS_UI_DESTINATION`

User interface destination.

### `NTMS_NUMBER_OF_OBJECT_TYPES`

## Remarks

The following table show the relationship of RSM objects.

| Container | Object |
| --- | --- |
| Library | Changer |
|  | Door |
|  | Drive |
|  | Library request |
|  | Media type |
|  | Physical media |
|  | Port |
|  | Slot |
| Logical media | Side |
| Media pool | Logical media |
|  | Media pool |
|  | Physical media |
| NULL | Changer |
|  | Changer type |
|  | Computer |
|  | Door |
|  | Drive |
|  | Drive type |
|  | Library |
|  | Library request |
|  | Logical media |
|  | Media pool (free, unrecognized, import, and application root) |
|  | Media type |
|  | Operator request |
|  | Port |
|  | Physical media |
|  | Side |
| Physical Media | Side |

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[SetNtmsObjectInformation](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectinformation)