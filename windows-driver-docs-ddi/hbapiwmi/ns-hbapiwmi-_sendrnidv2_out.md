# _SendRNIDV2_OUT structure

## Description

The SendRNIDV2_OUT structure is used to report the output parameter data of the [SendRNIDV2](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnidv2) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalRspBufferSize`

Contains the size in bytes of the results of the version 2 request node identification data (RNIDV2) command.

### `ActualRspBufferSize`

Contains the size in bytes of the data that was actually retrieved.

### `RspBuffer`

Contains the results of the RNIDV2 command.

## Remarks

The WMI tool suite generates a declaration of the SendRNIDV2_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRNIDV2](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnidv2)