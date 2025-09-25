# _GetPortAttributesByWWN_OUT structure

## Description

The GetPortAttributesByWWN_OUT structure is used to report the output parameter data of the [GetPortAttributesByWWN](https://learn.microsoft.com/windows-hardware/drivers/storage/getportattributesbywwn) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `PortAttributes`

Contains a structure of type [MSFC_HBAPortAttributesResults](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults) that holds the port attributes to be reported.

## Remarks

The WMI tool suite generates a declaration of the GetPortAttributesByWWN_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetPortAttributesByWWN](https://learn.microsoft.com/windows-hardware/drivers/storage/getportattributesbywwn)

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[MSFC_HBAPortAttributesResults](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults)