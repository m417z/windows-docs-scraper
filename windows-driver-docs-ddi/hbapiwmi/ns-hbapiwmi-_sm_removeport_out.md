# _SM_RemovePort_OUT structure

## Description

The SM_RemovePort_OUT structure is used to receive output parameters from the SM_RemovePort WMI method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

## Remarks

The WMI tool suite generates a declaration of the SM_RemovePort_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_EventControl WMI class.