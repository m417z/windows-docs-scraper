# _GetBindingCapability_IN structure

## Description

The GetBindingCapability_IN structure is used by a WMI client to deliver the input parameter data of the [GetBindingCapability](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability) WMI method to the HBA miniport driver.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port whose persistent bindings are to be retrieved.

## Remarks

The WMI tool suite generates a declaration of the GetBindingCapability_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## See also

[GetBindingCapability](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability)