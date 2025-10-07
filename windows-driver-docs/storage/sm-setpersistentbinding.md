# SM\_SetPersistentBinding function

The SM\_SetPersistentBinding method sets the bindings that are used by the HBA miniport driver to map the OS-specific LUN information to the fibre channel protocol (FCP) identifiers for the logical units.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the port whose persistent bindings will be set.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port that is discovered by using the physical fibre channel port. It has a value of zero if no SMP port has been discovered by using the physical fibre channel port.

*InEntryCount*
The number of binding entries that the WMI provider can report in the Entry parameter.

*Entry*
An array of structures of type SMHBA\_SCSIENTRY that describes an HBA's bindings between the operating system and the SAS identifiers.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a GetPersistentBinding\_OUT structure.

*OutStatusCount*
The total number of persistent bindings that are retrieved by the SM\_GetPersistentBinding method. This value will be less than or equal to TotalEntryCount.

*EntryStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a GetPersistentBinding\_OUT structure.

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

[**SM\_SetPersistentBinding\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setpersistentbinding_in)

[**SM\_SetPersistentBinding\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_setpersistentbinding_out)

