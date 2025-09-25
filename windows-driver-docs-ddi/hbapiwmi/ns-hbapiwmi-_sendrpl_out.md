# _SendRPL_OUT structure

## Description

The SendRPL_OUT structure is used to report the output parameter data of the [SendRPL](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrpl) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalRspBufferSize`

Contains the size in bytes of the results of the read port list (RPL) command.

### `ActualRspBufferSize`

Contains the size in bytes of the data that was actually retrieved.

### `RspBuffer`

Contains the results of the read port list (RPL) command.

## Remarks

The WMI tool suite generates a declaration of the SendRPL_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRPL](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrpl)