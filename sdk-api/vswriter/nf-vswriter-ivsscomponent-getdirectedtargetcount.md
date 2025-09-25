# IVssComponent::GetDirectedTargetCount

## Description

The
**GetDirectedTargetCount** method returns the number of directed target specifications associated with the current component. Either a writer or a requester can call this method.

## Parameters

### `pcDirectedTarget` [out]

The address of a caller-allocated variable that receives the number of directed target specifications.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddDirectedTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddirectedtarget)

[IVssComponent::GetDirectedTarget](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getdirectedtarget)