# IVssComponent::GetLogicalPath

## Description

The
**GetLogicalPath** method returns the logical path of this component.

Either a writer or a requester can call this method.

## Parameters

### `pbstrPath` [out]

Pointer to a string containing the logical path of the component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | This component has no logical path. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

The caller should free the memory held by the *pbstrPath* parameter by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

Logical paths are not required of components. A component without a logical path will return S_FALSE.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)