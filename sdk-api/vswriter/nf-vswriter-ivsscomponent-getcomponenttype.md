# IVssComponent::GetComponentType

## Description

The
**GetComponentType** method returns the type of this component in terms of the
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) enumeration.

Either a writer or a requester can call this method.

## Parameters

### `pct` [out]

The address of a caller-allocated variable that receives a
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) enumeration value that specifies the type of the component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)