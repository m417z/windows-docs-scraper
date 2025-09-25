# _SetPersistentEntry_IN structure

## Description

The SetPersistentEntry_IN structure is used by a WMI client to deliver the input parameter data of the [SetPersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/setpersistententry) WMI method to the HBA miniport driver.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port whose persistent bindings will be changed.

### `Binding`

Contains a structure of type [HBAFCPBindingEntry2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry2) that indicates the binding to be removed from the indicated port's list of bindings.

## Remarks

The WMI tool suite generates a declaration of the SetPersistentEntry_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[SetPersistentEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/setpersistententry)