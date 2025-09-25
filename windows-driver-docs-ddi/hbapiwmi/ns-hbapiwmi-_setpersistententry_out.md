# _SetPersistentEntry_OUT structure

## Description

The SetPersistentEntry_OUT structure is used to report the output parameter data of the [SetPersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/setpersistententry) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the SetPersistentEntry_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[SetPersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/setpersistententry)