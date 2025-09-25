# _GetBindingSupport_IN structure

## Description

The GetBindingSupport_IN structure is used by a WMI client to deliver the input parameter data of the [GetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingsupport) WMI method to the HBA miniport driver.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port whose persistent bindings are to be retrieved.

## Remarks

The WMI tool suite generates a declaration of the GetBindingSupport_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetBindingSupport](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingsupport)