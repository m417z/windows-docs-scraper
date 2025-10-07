# SetBindingSupport function

The **SetBindingSupport** method sets the binding capabilities that are currently enabled for the indicated port.

## Parameters

*PortWWN*
A worldwide name that indicates the port whose persistent bindings will be retrieved.

*BindType*
A bitmap that indicates the ability of an HBA and its miniport driver to provide a specific set of features related to persistent binding. For a list of values that this parameter can have, see the description of the [HBA\_BIND\_TYPE](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-bind-type) WMI class qualifier.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SetBindingSupport\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setbindingsupport_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[**SetBindingSupport**](https://learn.microsoft.com/windows-hardware/drivers/storage/setbindingsupport)

[**SetBindingSupport\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setbindingsupport_in)

[**SetBindingSupport\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setbindingsupport_out)

