# IVssComponent::GetNewTarget

## Description

The
**GetNewTarget** method returns the new file restoration locations for the selected component or component set. (See
[Working with Selectability and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for information on selecting components.)

Either a writer or a requester can call this method.

## Parameters

### `iNewTarget` [in]

Index number of the new target. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of new targets associated with a given component. The value of *n* is returned by
[IVssComponent::GetNewTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtargetcount).

### `ppFiledesc` [out]

Doubly indirect pointer to an
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object containing the new target restore location information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified item was not found. |

## Remarks

New targets returned by
**GetNewTarget** may be those not only of files in the current component but to files in any of its nonselectable subcomponents.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetNewTargetCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getnewtargetcount)