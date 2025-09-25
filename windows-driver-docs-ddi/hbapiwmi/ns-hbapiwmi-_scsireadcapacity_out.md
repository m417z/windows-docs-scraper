# ScsiReadCapacity_OUT structure (hbapiwmi.h)

## Description

The ScsiReadCapacity_OUT structure is used to report the output data of the [**ScsiReadCapacity**](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [**HBA_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `ResponseBufferSize`

Indicates the size in bytes of the buffer that will hold the results of the read capacity command.

### `SenseBufferSize`

Indicates the size in bytes of the buffer that will hold the SCSI sense data that results from the read capacity command.

### `ScsiStatus`

Contains the status of the SCSI read capacity command.

### `ResponseBuffer[1]`

Contains the results of the SCSI read capacity command.

## Remarks

The WMI tool suite generates a declaration of the ScsiReadCapacity_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[**HBA_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**ScsiReadCapacity**](https://learn.microsoft.com/windows-hardware/drivers/storage/scsireadcapacity6)