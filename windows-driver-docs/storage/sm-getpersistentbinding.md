# SM\_GetPersistentBinding function

The SM\_GetPersistentBinding method retrieves the bindings that an HBA miniport driver uses. These bindings map the OS-specific LUN information to the fibre channel protocol (FCP) identifiers for the logical units.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the port whose persistent bindings will be retrieved.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port that was discovered by using the physical fibre channel port. It has a value of zero if no SMP port has been discovered by using the physical fibre channel port.

*InEntryCount*
The number of binding entries that the WMI provider can report in the Entry parameter.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see the [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) structure. The miniport driver returns this information in the HBAStatus member of a GetPersistentBinding\_OUT structure.

*TotalEntryCount*
The total number of persistent bindings that are associated with the HBA.

*OutEntryCount*
The total number of persistent bindings that are retrieved by the SM\_GetPersistentBinding method. This value will be less than or equal to TotalEntryCount.

*Bindings*
An array of structures of type MS\_SMHBA\_BINDINGENTRY that describe an HBA's bindings between the operating system and the fibre channel protocol (FCP) identifiers.

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

[**SM\_GetPersistentBinding\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getpersistentbinding_in)

[**SM\_GetPersistentBinding\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getpersistentbinding_out)

