# _RemovePersistentEntry_OUT structure

## Description

The RemovePersistentEntry_OUT structure is used to report the output parameter data of the [RemovePersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistententry) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the RemovePersistentEntry_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[RemovePersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistententry)