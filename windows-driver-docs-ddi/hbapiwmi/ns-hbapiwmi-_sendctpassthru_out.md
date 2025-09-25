# _SendCTPassThru_OUT structure

## Description

The SendCTPassThru_OUT structure is used to report the output parameter data of the [SendCTPassThru](https://learn.microsoft.com/windows-hardware/drivers/storage/sendctpassthru) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalResponseBufferCount`

Contains the size in bytes of the results common transport (CT) command.

### `ActualResponseBufferCount`

Contains the size in bytes of the data that was actually retrieved.

### `ResponseBuffer`

Contains the results of the common transport command.

## Remarks

The WMI tool suite generates a declaration of the SendCTPassThru_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendCTPassThru](https://learn.microsoft.com/windows-hardware/drivers/storage/sendctpassthru)