# IoSetPartitionInformationEx function

## Description

For the disk represented by *DeviceObject*, the **IoSetPartitionInformationEx** routine initializes a partition table entry with the information specified in the [SET_PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information_ex) structure.

## Parameters

### `DeviceObject` [in]

Pointer to the device object representing the device on which the partition type is to be set.

### `PartitionNumber` [in]

Specifies the partition number on the device whose partition type is to be set.

### `PartitionInfo` [in]

A structure whose *PartitionType* member specifies the type for the partition. For the currently defined *PartitionType* values [PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_partition_information).

## Return value

If **IoSetPartitionInformationEx** returns STATUS_SUCCESS, the disk driver updates its notion of the partition type for this partition in its device extension.

## Remarks

**IoSetPartitionInformationEx** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_SET_PARTITION_INFO_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_partition_info_ex) disk I/O request instead.

This routine is called when a disk device driver is requested to set partition information in a partition table entry by an IRP_MJ_DEVICE_CONTROL request. This request is generally issued by the format utility, which performs I/O control functions on the partition. The driver passes a pointer to the device object representing the physical disk and the number of the partition associated with the device object that the format utility has open. Since the HAL routines that underlie **IoSetPartitionInformationEx** were developed before support for dynamic partitioning was implemented, they do not distinguish between the *partitionordinal* (that is the order of a partition on a disk) and the *partition number* (the partition number assigned to a partition in order to identify it to the system). Drivers must call **IoSetPartitionInformationEx** using the *ordinal* number of the partition and not the actual partition number.

If the partition is a Master Boot Record (MBR) type partition, **IoSetPartitionInformationEx** is limited to setting the partition style, and the partition style, which is represented as an unsigned character. See SET_PARTITION_INFORMATION_MBR for further information about these values.

If the partition is a GUID Partition Table (GPT) partition, **IoSetPartitionInformationEx** sets the following values: the partition style, the partition type, represented by a GUID instead of an integer as was the case with MBR partitions; a partition ID, also represented by a GUID; a set of attributes (see the Extensible Firmware Interface for a description of these attributes); and a Unicode name for the partition. See [SET_PARTITION_INFORMATION_GPT](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff566196(v=vs.85)) for further information about these values.

This routine is synchronous and must be called by the disk driver's Dispatch routine or by a driver thread. Thus, all user and file system threads must be prepared to enter a wait state when issuing the device control request to set the partition type for the device.

This routine operates under the assumption that the partition number passed in by the disk driver actually exists.

This routine must be called at IRQL = PASSIVE_LEVEL because it uses a kernel event object to synchronize I/O completion on the device. The event cannot be set to the Signaled state without queuing and executing the I/O system's special kernel APC routine for I/O completion.

## See also

[IoReadPartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontable)

[IoSetPartitionInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformation)

[IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable)

[SET_PARTITION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information)

[SET_PARTITION_INFORMATION_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_set_partition_information_ex)