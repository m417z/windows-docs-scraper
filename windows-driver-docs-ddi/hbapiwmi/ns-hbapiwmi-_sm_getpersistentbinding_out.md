# _SM_GetPersistentBinding_OUT structure

## Description

The SM_GetPersistentBinding_OUT structure is used to receive output parameters from the SM_GetPersistentBinding method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalEntryCount`

The total number of persistent bindings that are associated with the HBA.

### `OutEntryCount`

The total number of mappings that are retrieved. This value will be less than or equal to TotalEntryCount.

### `Entry`

An array of structures of type SMHBA_SCSIENTRY that describes an HBA's bindings between the operating system and the SAS identifiers.

## Remarks

The WMI tool suite generates a declaration of the SM_GetPersistentBinding_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.