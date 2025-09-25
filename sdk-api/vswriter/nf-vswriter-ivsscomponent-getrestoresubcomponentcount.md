# IVssComponent::GetRestoreSubcomponentCount

## Description

The
**GetRestoreSubcomponentCount** method returns the number of subcomponents associated with a component.

Either a writer or a requester can call this method.

## Parameters

### `pcRestoreSubcomponent` [out]

The address of a caller-allocated variable that receives the number of subcomponents that are associated with a component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetRestoreSubcomponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoresubcomponent)