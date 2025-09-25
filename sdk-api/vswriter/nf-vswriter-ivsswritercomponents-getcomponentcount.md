# IVssWriterComponents::GetComponentCount

## Description

The
**GetComponentCount** method returns the number of a given writer's components explicitly stored in the Backup Components Document.

## Parameters

### `pcComponents` [out]

Pointer to the number of a writer's components stored in the Backup Components Document.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)