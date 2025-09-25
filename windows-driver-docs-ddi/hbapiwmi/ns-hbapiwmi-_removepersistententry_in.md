# _RemovePersistentEntry_IN structure

## Description

The RemovePersistentEntry_IN structure is used by a WMI client to deliver input parameter data to the [RemovePersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistententry) WMI method.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port for which a persistent binding will be removed.

### `Binding`

Contains a structure of type [HBAFCPBindingEntry2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry2) that indicates the binding to be removed from the indicated port's list of bindings.

## Remarks

The WMI tool suite generates a declaration of the RemovePersistentEntry_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[RemovePersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/removepersistententry)