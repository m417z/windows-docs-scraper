# _SendCTPassThru_IN structure

## Description

The SendCTPassThru_IN structure is used to deliver input parameter data to the [SendCTPassThru](https://learn.microsoft.com/windows-hardware/drivers/storage/sendctpassthru) WMI method.

## Members

### `PortWWN`

Contains a worldwide name for the HBA through which the target is accessed.

### `RequestBufferCount`

Indicates the size in bytes of the buffer that will hold the results of the common transport command.

### `RequestBuffer`

Contains the results of the common transport command.

## Remarks

The WMI tool suite generates a declaration of the SendCTPassThru_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendCTPassThru](https://learn.microsoft.com/windows-hardware/drivers/storage/sendctpassthru)