# _ScsiReadCapacity_IN structure (hbapiwmi.h)

## Description

The ScsiReadCapacity_IN structure is used to deliver input parameter data to the [ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6) WMI method.

## Members

### `Cdb`

Contains the command descriptor block that holds the SCSI read capacity command to be sent to the target device.

### `HbaPortWWN`

Contains a worldwise name for the HBA through which the target is accessed.

### `DiscoveredPortWWN`

Contains a worldwide name for the port through which the target device is accessed.

### `FcLun`

Indicates the logical unit number of the logical unit that will receive the SCSI read capacity command.

## Remarks

The WMI tool suite generates a declaration of the ScsiReadCapacity_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[ScsiReadCapacity](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6)