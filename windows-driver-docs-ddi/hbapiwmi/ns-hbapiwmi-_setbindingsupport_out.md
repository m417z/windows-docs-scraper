# _SetBindingSupport_OUT structure

## Description

The SetBindingSupport_OUT structure is used to report the output parameter data of the [SetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/setbindingsupport) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the SetBindingSupport_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[SetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/setbindingsupport)