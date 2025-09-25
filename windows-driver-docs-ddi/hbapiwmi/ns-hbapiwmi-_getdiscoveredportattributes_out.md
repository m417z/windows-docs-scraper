# _GetDiscoveredPortAttributes_OUT structure

## Description

The GetDiscoveredPortAttributes_OUT structure is used to report the output parameter data of the [GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `PortAttributes`

Contains a structure of type [MSFC_HBAPortAttributesResults](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults) that holds the port attributes to report.

## Remarks

The WMI tool suite generates a declaration of the GetDiscoveredPortAttributes_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes)