# _CDROM_SET_STREAMING structure

## Description

The CDROM_SET_SPEED structure is used with the [IOCTL_CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_set_speed) request to set the spindle speed of a CD-ROM drive during isochronous transfers that permit some data loss.

## Members

### `RequestType`

A [CDROM_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_speed_request)-typed value that indicates which multimedia command to use when setting the spindle speed.

### `ReadSize`

The number of kilobytes to read in each unit of time, where a unit of time is specified by **ReadTime**. A value of 0xFFFF in **ReadSize** selects the optimal data transfer speed of the drive.

### `ReadTime`

The number of milliseconds in which to read **ReadSize** kilobytes of data.

### `WriteSize`

The number of kilobytes to write in each unit of time, where a unit of time is defined by **WriteTime**. A value of 0xFFFF in **WriteSize** selects the optimal data transfer speed of the drive.

### `WriteTime`

The number of milliseconds in which to write **WriteSize** kilobytes of data.

### `StartLba`

The first logical block address, in bytes, of the IOCTL_CDROM_SET_SPEED request.

### `EndLba`

The last logical block address, in bytes, of the IOCTL_CDROM_SET_SPEED request.

### `RotationControl`

A [WRITE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_write_rotation)-typed value that indicates whether the device will write to the media by using CLV (constant linear velocity) rotation or CLA (constant angular velocity) rotation.

### `RestoreDefaults`

A BOOLEAN value that, when **TRUE**, instructs the CD-ROM class driver to make the CD-ROM drive run at its default spindle speed. A value of **FALSE** instructs the class driver to calculate the spindle speed from the **ReadSize**, **ReadTime**, **WriteSize**, and **WriteTime** members of this structure.

### `SetExact`

A BOOLEAN value that, when **TRUE**, instructs the CD-ROM class driver to set the CD-ROM drive to the exact speed that is specified by the **ReadSize**, **ReadTime**, **WriteSize**, and **WriteTime** members of this structure. If the class driver cannot set the spindle speed to the exact value that is specified by these members, it fails the request. A value of **FALSE** in **SetExact** instructs the class driver to make the spindle speed of the drive match as closely as possible the speed that is specified by **ReadSize**, **ReadTime**, **WriteSize**, and **WriteTime**; the class driver does not fail the request if the drive cannot run at the exact value that these members specify.

### `RandomAccess`

A BOOLEAN value that, when **TRUE**, instructs the CD-ROM class driver to configure the CD-ROM drive, so that it will switch back and forth between read and write operations to maximize performance (data throughput), even if switching between read and write operations causes a particular read or write operation to occur more slowly. In other words, a value of **TRUE** in **RandomAccess** permits the drive to lower the speed of some individual read and write operations to ensure better overall performance in data transfers. A value of **FALSE** instructs the CD-ROM class driver to configure the CD-ROM drive to guarantee the speeds of read and write operations, independent of one another. The data transfer rate of each operation is rigid, and the drive will not alter the speed to achieve performance gains.

### `Persistent`

A BOOLEAN value that, when **TRUE**, instructs the CD-ROM class driver to configure the CD-ROM drive to restore the default speed when the user changes the media. A value of **FALSE** instructs the CD-ROM class driver to configure the CD-ROM drive to maintain its speed until the computer restarts or the class driver changes the speed with another command.

## See also

[CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_set_speed)

[CDROM_SPEED_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_speed_request)

[IOCTL_CDROM_SET_SPEED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_set_speed)

[WRITE_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_write_rotation)