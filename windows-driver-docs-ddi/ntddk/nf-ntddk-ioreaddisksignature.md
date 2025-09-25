# IoReadDiskSignature function

## Description

The **IoReadDiskSignature** routine reads the disk signature information for the partition table of a disk.

## Parameters

### `DeviceObject` [in]

Specifies the device object for the disk to read.

### `BytesPerSector` [in]

Specifies the number of bytes per sector of the disk.

### `Signature` [out]

Pointer to a [DISK_SIGNATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_disk_signature) structure the routine uses to return the disk signature information.

## Return value

The routine returns STATUS_SUCCESS on success, or the appropriate error code on failure. The routine returns STATUS_DISK_CORRUPT_ERROR if it detects that the disk partition table is corrupted.

## Remarks

**IoReadDiskSignature** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry_ex) I/O request instead.

## See also

[DISK_SIGNATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_disk_signature)

[IOCTL_DISK_GET_DRIVE_GEOMETRY_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_get_drive_geometry_ex)