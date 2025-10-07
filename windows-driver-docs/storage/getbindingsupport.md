# GetBindingSupport function

The **GetBindingSupport** method retrieves the binding capabilities that are currently enabled for the indicated port.

## Parameters

*PortWWN\[8\]*
A worldwide name that indicates the port whose persistent bindings will be retrieved.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetBindingSupport\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getbindingsupport_out) structure.

*BindType*
A bitmap that indicates the ability of an HBA and its miniport driver to provide a specific set of features related to persistent binding. For a list of values that this parameter can have, see the description of the [HBA\_BIND\_TYPE](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-bind-type) WMI class qualifier.

## Return value

Not applicable to WMI methods.

## Remarks

This **GetBindingSupport** method returns the binding capability that is currently enabled, whereas the [**GetBindingCapability**](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability) method indicates the binding capability of the port without reference to whether particular bindings are enabled or not.

This WMI method belongs to the [MSFC\_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[**GetBindingCapability**](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingcapability)

[**GetBindingSupport**](https://learn.microsoft.com/windows-hardware/drivers/storage/getbindingsupport)

[**GetBindingSupport\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getbindingsupport_in)

[**GetBindingSupport\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getbindingsupport_out)

