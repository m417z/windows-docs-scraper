# ScsiReportLuns_IN structure (hbapiwmi.h)

## Description

The ScsiReportLuns_IN structure is used to deliver input parameter data to the [**ScsiReportLuns**](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6) WMI method.

## Members

### `Cdb[12]`

Contains the command descriptor block that holds the SCSI report LUNs command to be sent to the target device.

### `HbaPortWWN[8]`

Contains a worldwise name for the HBA through which the target is accessed.

### `DiscoveredPortWWN[8]`

Contains a worldwide name for the port through which the target device is accessed.

## Remarks

The WMI tool suite generates a declaration of the ScsiReportLuns_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[**ScsiReportLuns**](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireportluns6)