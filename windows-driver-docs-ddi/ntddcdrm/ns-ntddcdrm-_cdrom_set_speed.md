# _CDROM_SET_SPEED structure

## Description

The CDROM_SET_SPEED structure is used with the [IOCTL_CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_set_speed) request to set the spindle speed of a CD-ROM drive during data transfers in which no data loss is permitted.

## Members

### `RequestType`

A [CDROM_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_speed_request)-typed value that indicates the type of set speed operation for [IOCTL_CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_set_speed) to perform.

### `ReadSpeed`

The read speed, in kilobytes per second.

### `WriteSpeed`

The write speed, in kilobytes per second.

### `RotationControl`

A [WRITE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_write_rotation)-typed value that indicates whether the drive uses constant angular velocity (CAV) or constant linear velocity (CLV) rotation when it writes to a CD.

## See also

[CDROM_SET_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_set_streaming)

[CDROM_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_speed_request)

[IOCTL_CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_set_speed)

[WRITE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_write_rotation)