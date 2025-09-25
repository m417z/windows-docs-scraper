# _SM_GetTargetMapping_IN structure

## Description

The SM_GetTargetMapping_IN structure is used to provide input parameters to the SM_GetTargetMapping method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `InEntryCount`

The number of persistent bindings that are associated with the HBA.

## Remarks

The WMI tool suite generates a declaration of the SM_GetTargetMapping_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.