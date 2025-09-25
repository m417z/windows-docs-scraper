# _GetPortAttributesByWWN_IN structure

## Description

The GetPortAttributesByWWN_IN structure is used by a WMI client to deliver input parameter data to the [GetPortAttributesByWWN](https://learn.microsoft.com/windows-hardware/drivers/storage/getportattributesbywwn) WMI method.

## Members

### `wwn`

Contains a worldwide name that identifies a port of type FC_Port.

## Remarks

The WMI tool suite generates a declaration of the GetPortAttributesByWWN_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

For a definition of FC_Port and a discussion of worldwide names, see the T11 committee's specification for *Fibre Channel HBA API* (FC-HBA).

## See also

[GetPortAttributesByWWN](https://learn.microsoft.com/windows-hardware/drivers/storage/getportattributesbywwn)