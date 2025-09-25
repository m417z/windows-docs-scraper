# _SendRNID_IN structure

## Description

The SendRNID_IN structure is used to deliver input parameter data to the [SendRNID](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnid) WMI method.

## Members

### `wwn`

Contains a worldwide name for the port to which the request node identification data (RNID) command is sent.

### `wwntype`

Deprecated. Do not use.

## Remarks

The WMI tool suite generates a declaration of the SendRNID_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRNID](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnid)