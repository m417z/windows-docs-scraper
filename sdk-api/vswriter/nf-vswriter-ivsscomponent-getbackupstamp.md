# IVssComponent::GetBackupStamp

## Description

The
**GetBackupStamp** method returns the backup stamp string stored by a writer for a given component.

Either a writer or a requester can call this method.

## Parameters

### `pbstrBackupStamp` [out]

The address of a caller-allocated variable that receives a string containing the backup stamp indicating the time at which the component was backed up.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | There is no time stamp associated with this component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

If no backup time stamp has been set,
**GetBackupStamp** returns S_FALSE.

If the call to **GetBackupStamp** is successful, the caller is responsible for freeing the string that is returned in the *pbstrBackupStamp* parameter by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

The string returned refers to all files in the component and any nonselectable subcomponents it has.

The backup stamp retrieved by
**GetBackupStamp** is generally set by a writer by a call to
[IVssComponent::SetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupstamp) from within the [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p) event handler,
[CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot).

Requesters merely store the backup stamps in the Backup Components Document; they do not make direct use of the backup stamp, know how to generate it, or understand its format.

## See also

[IVssBackupComponents::SetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setpreviousbackupstamp)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::SetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupstamp)