# _GetBindingCapability_OUT structure

## Description

The GetBindingCapability_OUT structure is used by a WMI provider to report the output parameter data of the [GetBindingCapability](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `BindType`

Indicates the ability of an HBA and its miniport driver to provide a specific set of features related to persistent binding. For a list of values that this parameter can have, see the description of the HBA_BIND_TYPE WMI class qualifier.

## Remarks

The WMI tool suite generates a declaration of the GetBindingCapability_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetBindingCapability](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability)