# _SM_GetBindingCapability_IN structure

## Description

The SM_GetBindingCapability_IN structure is used to provide input parameters to the SM_GetBindingCapability method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

## Remarks

The WMI tool suite generates a declaration of the SM_GetBindingCapability_IN structure in *Hbapiwmi.h* when it compiles the SM_TargetInformationMethod WMI class.