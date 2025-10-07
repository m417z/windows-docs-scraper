# SM\_RemovePersistentBinding function

The SM\_RemovePersistentBinding method removes one or more persistent bindings to the specified SCSI IDs for the specified adapter port.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the port whose persistent bindings will be removed.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port that was discovered by using the physical fibre channel port. It has a value of zero if no SMP port has been discovered by using the physical fibre channel port.

*EntryCount*
The number of binding entries that the WMI provider can report in the Entry parameter.

*Entry*
A list of MS\_SMHBA\_BINDINGENTRY types for persistent binding.

*HBAStatus*
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

[**SM\_RemovePersistentBinding\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removepersistentbinding_in)

[**SM\_RemovePersistentBinding\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_removepersistentbinding_out)

