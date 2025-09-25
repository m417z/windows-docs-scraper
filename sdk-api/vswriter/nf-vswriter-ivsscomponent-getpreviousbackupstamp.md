# IVssComponent::GetPreviousBackupStamp

## Description

The
**GetPreviousBackupStamp** method returns a previous backup stamp loaded by a requester in the Backup Components Document. The value is used by a writer when deciding if files should participate in differential or incremental backup operation.

Either a writer or a requester can call this method.

## Parameters

### `pbstrBackupStamp` [out]

Pointer to a string containing the time stamp of a previous backup so that a differential or incremental backup can be correctly implemented.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | No previous backup time stamp has been set. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

For more information about backup stamps, see [Writer Role in Backing Up Complex Stores](https://learn.microsoft.com/windows/desktop/VSS/writer-role-in-backing-up-complex-stores) and [Requester Role in Backing Up Complex Stores](https://learn.microsoft.com/windows/desktop/VSS/requestor-role-in-backing-up-complex-stores).

The caller should free the memory held by the *pbstrBackupStamp* parameter by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

If there is no previous backup time stamp,
**GetPreviousBackupStamp** returns S_FALSE.

The string returned refers to all files in the component and any nonselectable subcomponents it has.

The backup stamp retrieved by
**GetPreviousBackupStamp** is set by a requester using
[IVssBackupComponents::SetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setpreviousbackupstamp).

Typically, the string used to set the value found by
**GetPreviousBackupStamp** was retrieved from a stored Backup Components Document or was stored by the requester as part of its own internal records.

## See also

[IVssBackupComponents::SetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setpreviousbackupstamp)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)