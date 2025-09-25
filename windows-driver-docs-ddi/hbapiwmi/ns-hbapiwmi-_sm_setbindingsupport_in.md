# _SM_SetBindingSupport_IN structure

## Description

The SM_SetBindingSupport_IN structure is used to provide input parameters to the SM_SetBindingSupport method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `Flags`

The HBA_BIND_CAPABILITY binding capabilities.

## Remarks

The WMI tool suite generates a declaration of the SM_SetBindingSupport_IN structure in *Hbapiwmi.h* when it compiles the MS_SMHBA_BindingEntry WMI class.