# _SM_AddLink_OUT structure

## Description

The SM_AddLink_OUT structure is used to receive output parameters from the SM_AddLink WMI method.

## Members

### `HBAStatus`

A value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

## Remarks

The WMI tool suite generates a declaration of the SM_AddLink_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_EventControl WMI class.