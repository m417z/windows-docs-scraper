# _SendLIRR_IN structure

## Description

The SendLIRR_IN structure is used to deliver parameter data to the [SendLIRR](https://learn.microsoft.com/windows-hardware/drivers/storage/sendlirr) WMI method.

## Members

### `SourceWWN`

Contains a worldwide name for the local port through which the link incident record registration (LIRR) command is sent.

### `DestWWN`

Contains a worldwide name for the destination port.

### `Function`

Contains the code that identifies which registration function is to be performed. For an explanation of which values can be assigned to this member, see the T11 committee's *Fibre Channel Framing and Signaling* specification.

### `Type`

Indicates the device type for which link information is requested. For an explanation of which values can be assigned to this member, see the T11 committee's *Fibre Channel Framing and Signaling* specification.

## Remarks

The WMI tool suite generates a declaration of the SendLIRR_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendLIRR](https://learn.microsoft.com/windows-hardware/drivers/storage/sendlirr)