# _RemoveTarget_OUT structure

## Description

The RemoveTarget_OUT structure is used by an HBA miniport driver to report the output parameter data of the [RemoveTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/removetarget) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the RemoveTarget_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class).

## See also

[RemoveTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/removetarget)