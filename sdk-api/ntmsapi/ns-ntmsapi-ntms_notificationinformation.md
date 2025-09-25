# NTMS_NOTIFICATIONINFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_NOTIFICATIONINFORMATION** structure defines an object and operation that occurred in the RSM database.

## Members

### `dwOperation`

Operation that occurred on the object. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NTMS_OBJ_INSERT** | New object was inserted. |
| **NTMS_OBJ_DELETE** | Object was deleted. |
| **NTMS_OBJ_UPDATE** | Object was updated. |

### `ObjectId`

Object Identifier.

## See also

[WaitForNtmsNotification](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-waitforntmsnotification)