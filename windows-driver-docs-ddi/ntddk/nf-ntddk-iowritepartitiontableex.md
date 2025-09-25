## Description

The **IoWritePartitionTableEx** routine writes partition tables from the entries in the partition list buffer for each partition on the disk represented by the given device object.

## Parameters

### `DeviceObject` [in]

Pointer to the device object representing the disk whose partition tables are to be written.

### `DriveLayout`

Pointer to the drive layout buffer that contains the partition list entries. For more detailed information see [**DRIVE_LAYOUT_INFORMATION_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_drive_layout_information_ex).

## Return value

**IoWritePartitionTableEx** returns a status code of STATUS_SUCCESS if all writes were completed without error. In case of failure, the error codes returned by **IoWritePartitionTableEx** might include, but are not limited to, the following list:

| Return code | Description |
|--|--|
| **STATUS_DEVICE_NOT_READY** | Indicates a failure read the correct disk geometry. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates a failure to allocate necessary resources (for example, heap memory, IRPs, and so on). |
| **STATUS_UNSUCCESSFUL** | Indicates that sector zero did not have the expected MBR disk signature. |

## Remarks

**IoWritePartitionTableEx** replaces the obsolete routine [IoWritePartitionTable](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iowritepartitiontable). Unlike the older routine, it can write to GUID Partition Tables as well as Master Boot Record Partition Tables.

**IoWritePartitionTableEx** must only be used by disk drivers. Other drivers should use the [IOCTL_DISK_SET_DRIVE_LAYOUT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_set_drive_layout_ex) disk I/O request instead.

When a disk device driver receives an IRP_MJ_DEVICE_CONTROL request to set the partition type in a partition table entry, or to repartition the disk, it should call **IoWritePartitionTableEx**. The device control request is generally issued by the format utility, which performs I/O control functions on the partitions and disks in the machine.

To reset a partition type, the driver passes a pointer to the device object, representing the physical disk, and the number of the partition associated with the device object that the format utility has open. When a disk is to be repartitioned dynamically, the disk driver must tear down its set of device objects representing the current disk partitions and create a new set of device objects representing the new partitions on the disk.

In order tot create or delete partitions a full description of the system must be obtained by a call to [IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex). The drive layout structure can be modified by the system format utility to reflect a new configuration of the disk.

**IoWritePartitionTableEx** is synchronous. It must be called by the disk driver's Dispatch routine or by a driver thread. Thus, all user and file system threads must be prepared to enter a wait state when issuing the device control request to reset partition types for the device.

## See also

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[IoReadPartitionTableEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioreadpartitiontableex)

[IoSetPartitionInformationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetpartitioninformationex)