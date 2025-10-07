# SM\_SetBindingSupport function

The SM\_SetBindingSupport method sets the binding capabilities for the indicated port.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the port whose persistent bindings will be retrieved.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port discovered by using the physical fibre channel port. It has a value of zero if no SMP port has been discovered by using the physical fibre channel port.

*Flags*
A bitmap that indicates the ability of an HBA and its miniport driver to provide a specific set of features that are related to persistent binding. For a list of values that this parameter can have, see the description of the HBA\_BIND\_TYPE WMI class qualifier.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SetBindingSupport\_OUT structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the MS\_SM\_TargetInformationMethods WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SM\_SetBindingSupport\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setbindingsupport_in)

[**SM\_SetBindingSupport\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setbindingsupport_out)

