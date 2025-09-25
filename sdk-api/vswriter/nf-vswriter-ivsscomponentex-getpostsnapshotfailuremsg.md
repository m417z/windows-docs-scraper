# IVssComponentEx::GetPostSnapshotFailureMsg

## Description

Returns the [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) failure message string that a writer has set for a given component.

Both writers and requesters can call this method. Writers should call this method after the [IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) asynchronous operation has completed.

## Parameters

### `pbstrFailureMsg` [out]

A pointer to a null-terminated wide character string containing the failure message that describes an error that occurred
while processing a [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p)
event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The failure message was successfully obtained. |
| **S_FALSE** | No [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) failure message was set for the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

The caller is responsible for freeing the string that the *pbstrFailureMsg* parameter points to by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## See also

[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)

[IVssComponentEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponentex)

[IVssComponentEx::SetPostSnapshotFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex-setpostsnapshotfailuremsg)