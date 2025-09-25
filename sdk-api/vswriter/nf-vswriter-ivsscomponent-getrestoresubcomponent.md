# IVssComponent::GetRestoreSubcomponent

## Description

The
**GetRestoreSubcomponent** method returns the specified subcomponent associated with a given component.

Either a writer or a requester can call this method.

## Parameters

### `iComponent` [in]

Index of the subcomponent. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of subcomponents associated with a given component. The value of *n* is returned by
[IVssComponent::GetRestoreSubcomponentCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoresubcomponentcount).

### `pbstrLogicalPath` [out]

Pointer to a string containing the logical path of the subcomponent. The logical path cannot be empty when working with subcomponents.

### `pbstrComponentName` [out]

Pointer to a string containing the name of the subcomponent. The string cannot be empty.

### `pbRepair` [out]

Reserved for future use.

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

The caller should free the memory held by the *pbstrLogicalPath* and *pbstrComponentName* parameters by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)