# _SM_SetPersistentBinding_IN structure

## Description

The SM_SetPersistentBinding_IN structure is used to provide input parameters to the SM_SetPersistentBinding method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `InEntryCount`

The number of persistent bindings that are associated with the HBA.

### `Entry`

A list of MS_SMHBA_BINDINGENTRY types for persistent binding.

## Remarks

The WMI tool suite generates a declaration of the SM_SetPersistentBinding_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.