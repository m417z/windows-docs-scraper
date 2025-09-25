# _SM_GetBindingSupport_IN structure

## Description

The SM_GetBindingSupport_IN structure is used to provide input parameters to the SM_GetBindingSupport method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

## Remarks

The WMI tool suite generates a declaration of the SM_GetBindingSupport_IN structure in *Hbapiwmi.h* when it compiles the MS_SMHBA_BindingEntry WMI class.