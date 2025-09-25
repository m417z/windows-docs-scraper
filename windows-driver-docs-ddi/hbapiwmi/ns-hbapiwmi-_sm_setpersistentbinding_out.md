# _SM_SetPersistentBinding_OUT structure

## Description

The SM_SetPersistentBinding_OUT structure is used to receive output parameters from the SM_SetPersistentBinding method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `OutStatusCount`

The number of entries.

### `EntryStatus`

The status of each entry.

## Remarks

The WMI tool suite generates a declaration of the SM__SetPersistentBinding_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.