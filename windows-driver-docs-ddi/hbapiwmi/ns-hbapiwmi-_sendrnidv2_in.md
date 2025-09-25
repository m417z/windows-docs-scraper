# _SendRNIDV2_IN structure

## Description

The SendRNIDV2_IN structure is used to deliver input parameter data to the [SendRNIDV2](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnidv2) WMI method.

## Members

### `PortWWN`

Contains a worldwide name for the local port through which the version 2 request node identification data (RNIDV2) command is sent.

### `DestWWN`

Contains a worldwide name for the destination port.

### `DestFCID`

Contains an address identifier of the destination port. For a description of the values that this member can have, see the T11 committee's specification for *Fibre Channel HBA API*.

### `NodeIdDataFormat`

Indicates the node identification data format. For a description of the values that this member can have, see the T11 committee's specification for *Fibre Channel HBA API*.

## Remarks

The WMI tool suite generates a declaration of the SendRNIDV2_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRNIDV2](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrnidv2)