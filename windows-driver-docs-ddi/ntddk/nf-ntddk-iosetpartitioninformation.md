# IoSetPartitionInformation function

## Description

The **IoSetPartitionInformation** routine is **obsolete** and is provided only to support existing drivers. New drivers must use [IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex).

**IoSetPartitionInformation** sets the partition type and number in a partition table entry for the disk represented by *DeviceObject*.

## Parameters

### `DeviceObject` [in]

Pointer to the device object representing the device on which the partition type is to be set.

### `SectorSize` [in]

Specifies the size, in bytes, of sectors on the disk.

### `PartitionNumber` [in]

Specifies the partition number on the device whose partition type is to be set.

### `PartitionType` [in]

Specifies the type for the partition. For a list of some of the key partition types see [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information).

## Return value

If **IoSetPartitionInformation** returns STATUS_SUCCESS, the disk driver updates its notion of the partition type for this partition in its device extension.

## Remarks

**IoSetPartitionInformation** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_SET_PARTITION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info) disk I/O request instead.

This routine is called when a disk device driver is asked to set the partition type in a partition table entry by an IRP_MJ_DEVICE_CONTROL request. This request is generally issued by the format utility, which performs I/O control functions on the partition. The driver passes a pointer to the device object representing the physical disk and the number of the partition associated with the device object that the format utility has open. Since the HAL routines that underlie **IoSetPartitionInformation** were developed before support of dynamic partitioning was implemented, they do not distinguish between the *partition ordinal* (that is the order of a partition on a disk) and the *partition number* (the partition number assigned to a partition in order to identify it to the system). Drivers must call **IoSetPartitionInformation** using the *ordinal* number of the partition and not the actual partition number.

This routine is synchronous and must be called by the disk driver's Dispatch routine or by a driver thread. Thus, all user and file system threads must be prepared to enter a wait state when issuing the device control request to set the partition type for the device.

This routine operates under the assumption that the partition number passed in by the disk driver actually exists.

This routine must be called at IRQL = PASSIVE_LEVEL because it uses a kernel event object to synchronize I/O completion on the device. The event cannot be set to the Signaled state without queuing and executing the I/O system's special kernel APC routine for I/O completion.

## See also

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)