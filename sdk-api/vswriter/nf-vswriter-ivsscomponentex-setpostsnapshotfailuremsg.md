# IVssComponentEx::SetPostSnapshotFailureMsg

## Description

Sets a [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) failure message string for a component.

This method can only be called by a writer's [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method.

## Parameters

### `wszFailureMsg` [in]

The address of a caller-allocated **NULL**-terminated wide character string containing the failure message that describes an error that occurred
while processing a [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p)
event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The failure message was successfully set. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | This method was not called by a writer's [CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method. |

## Remarks

The failure message that is set by
**SetPostSnapshotFailureMsg** applies to all files in the component and any subcomponents.

## See also

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[IVssComponentEx::GetPostSnapshotFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex-getpostsnapshotfailuremsg)