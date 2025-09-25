# _GetDiscoveredPortAttributes_IN structure

## Description

The GetDiscoveredPortAttributes_IN structure is used to pass input parameter data to the [GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes) WMI method.

## Members

### `PortIndex`

Indicates the index within the specified HBA of the port of type Nx_Port to query. For a definition of Nx_Port, see the T11 committee's specification for *Fibre Channel HBA API* (FC-HBA).

### `DiscoveredPortIndex`

Indicates the index within the specified HBA of the port of type FC_Port to query. For a definition of FC_Port, see the T11 committee's specification for *Fibre Channel HBA API* (FC-HBA).

## Remarks

The WMI tool suite generates a declaration of the GetDiscoveredPortAttributes_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetDiscoveredPortAttributes](https://learn.microsoft.com/windows-hardware/drivers/storage/getdiscoveredportattributes)