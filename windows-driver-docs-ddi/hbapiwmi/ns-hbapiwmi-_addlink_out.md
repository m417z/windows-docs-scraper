# _AddLink_OUT structure

## Description

The AddLink_OUT structure is used by an HBA miniport driver to report the status of a call to the [AddLink](https://learn.microsoft.com/windows-hardware/drivers/storage/addlink) WMI method.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

## Remarks

The WMI tool suite generates a declaration of the AddLink_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class).

## See also

[AddLink](https://learn.microsoft.com/windows-hardware/drivers/storage/addlink)

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[MSFC_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class)