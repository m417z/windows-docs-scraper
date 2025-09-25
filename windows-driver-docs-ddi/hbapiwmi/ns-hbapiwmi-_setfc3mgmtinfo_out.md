# _SetFC3MgmtInfo_OUT structure

## Description

The SetFC3MgmtInfo_OUT structure is used to report the output parameter data of the [SetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/setfc3mgmtinfo) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains the status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the SetFC3MgmtInfo_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/setfc3mgmtinfo)