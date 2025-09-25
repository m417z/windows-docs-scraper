# _SetBindingSupport_IN structure

## Description

The SetBindingSupport_IN structure is used to deliver input parameter data to the [SetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/setbindingsupport) WMI method.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port whose persistent bindings are to be retrieved.

### `BindType`

Contains a bitmap that indicates the ability of an HBA and its miniport driver to provide a specific set of features related to persistent binding. For a list of values that this parameter can have, see the description of the HBA_BIND_TYPE WMI class qualifier.

## Remarks

The WMI tool suite generates a declaration of the SetBindingSupport_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[SetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/setbindingsupport)