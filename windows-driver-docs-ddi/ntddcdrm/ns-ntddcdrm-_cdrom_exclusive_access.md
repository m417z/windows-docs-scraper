# _CDROM_EXCLUSIVE_ACCESS structure

## Description

The CDROM_EXCLUSIVE_ACCESS structure is used with the [IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access) request to query the access state of a CD-ROM device or to lock or unlock the device for exclusive access.

## Members

### `RequestType`

An [EXCLUSIVE_ACCESS_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_exclusive_access_request_type)-typed enumeration value that specifies the type of operation.

### `Flags`

A flag that specifies the characteristics of the operation. The meaning of the flag depends on the type of operation that **RequestType** specifies. The following table describes the possible values for **RequestType** and **Flags**:

| RequestType | Flags | Meaning |
| --- | --- | --- |
| **ExclusiveAccessQueryState** | Not applicable | Not applicable |
| **ExclusiveAccessLockDevice** | 0 | Requires that the caller dismount the file system |
| CDROM_LOCK_IGNORE_VOLUME | Ignores the file system mount and locks the device |
| **ExclusiveAccessUnlockDevice** | CDROM_NO_MEDIA_NOTIFICATIONS | Prevents the sending of a media removal notification and a media arrival notification on an exclusive access unlock |

## See also

[IOCTL_CDROM_EXCLUSIVE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_exclusive_access)