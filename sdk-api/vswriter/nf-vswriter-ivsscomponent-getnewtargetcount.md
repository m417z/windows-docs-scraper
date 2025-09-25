# IVssComponent::GetNewTargetCount

## Description

The
**GetNewTargetCount** method returns the number of new target restore locations associated with a given component.

Either a writer or a requester can call this method.

## Parameters

### `pcNewTarget` [out]

The address of a caller-allocated variable that receives the number of new target restore locations.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)