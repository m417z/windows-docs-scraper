# IVssComponent::GetBackupMetadata

## Description

The **GetBackupMetadata** method retrieves
private, writer-specific backup metadata that might have been set during a
[PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup) event by
[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup) using
[IVssComponent::SetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupmetadata).

Only a writer can call this method.

## Parameters

### `pbstrData` [out]

The address of a caller-allocated variable that receives a string containing the backup metadata that was added during an
[OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup) event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | There is no backup metadata associated with this component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

This method can be called at any time depending on the logic of a given writer.

If no backup metadata has been set,
**GetBackupMetadata** returns S_FALSE.

If the call to **GetBackupMetadata** is successful, the caller is responsible for freeing the string that is returned in the *pbstrMetadata* parameter by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::SetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupmetadata)