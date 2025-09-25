# _SendRLS_IN structure

## Description

The SendRLS_IN structure is used to deliver input parameter data to the [SendRLS](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrls) WMI method.

## Members

### `PortWWN`

Contains a worldwide name for the local port through which the read link error status block (RLS) command is sent.

### `DestWWN`

Contains a worldwide name for the destination port.

## Remarks

The WMI tool suite generates a declaration of the SendRLS_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRLS](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrls)