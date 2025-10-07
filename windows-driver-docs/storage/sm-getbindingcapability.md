# SM\_GetBindingCapability function

The SM\_GetBindingCapability method retrieves the binding capabilities for the indicated port.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the port whose persistent bindings will be retrieved.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port that was discovered by using the physical fibre channel port. It has a value of zero if no SMP port has been discovered by using the physical fibre channel port.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see the [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) structure. The miniport driver returns this information in the HBAStatus member of a GetBindingCapability\_OUT structure.

*HBAType*
The ability of an HBA and its miniport driver to provide a specific set of features that are related to persistent binding. For a list of values that this parameter can have, see the description of the HBA\_BIND\_TYPE WMI class qualifier.

## Return value

Not applicable to WMI methods.

## Remarks

The SM\_GetBindingSupport method returns the binding capability that is currently enabled, whereas the SM\_GetBindingCapability method indicates the binding capability of the port without reference to whether particular bindings are enabled or not. This WMI method belongs to the MS\_SM\_TargetInformationMethods WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SM\_GetBindingCapability\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getbindingcapability_in)

[**SM\_GetBindingCapability\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getbindingcapability_out)

