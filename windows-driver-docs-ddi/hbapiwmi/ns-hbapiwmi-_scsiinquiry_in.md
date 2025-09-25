# _ScsiInquiry_IN structure (hbapiwmi.h)

## Description

The ScsiInquiry_IN structure is used by a miniport driver to deliver input parameter data to the [ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry) WMI method.

## Members

### `Cdb`

Contains the command descriptor block that holds the SCSI inquiry command to be sent to the target device.

### `HbaPortWWN`

Contains a worldwise name for the HBA through which the target is accessed.

### `DiscoveredPortWWN`

Contains a worldwide name for the port through which the target device is accessed.

### `FcLun`

Indicates the logical unit number of the logical unit that will receive the SCSI inquiry command.

## Remarks

The WMI tool suite generates a declaration of the ScsiInquiry_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[ScsiInquiry](https://learn.microsoft.com/windows-hardware/drivers/storage/scsiinquiry)