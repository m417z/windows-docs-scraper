# IoCreateDisk function

## Description

The **IoCreateDisk** routine initializes a raw disk by creating a new partition table.

## Parameters

### `DeviceObject` [in]

Specifies the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) for the raw disk.

### `Disk` [in, optional]

Pointer to a [CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk) structure that specifies the type and parameters for the partition table. If *Disk* is **NULL**, the routine deletes the partition table on the disk.

## Return value

Returns STATUS_SUCCESS on success, or the appropriate error code on failure.

## Remarks

**IoCreateDisk** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk) I/O request instead.

## See also

[CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_create_disk)

[IOCTL_DISK_CREATE_DISK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_create_disk)