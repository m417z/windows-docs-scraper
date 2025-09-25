# IVssComponent::GetRestoreMetadata

## Description

The **GetRestoreMetadata** method retrieves
private, writer-specific restore metadata that might have been set during a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event by
[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore) using
[IVssComponent::SetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoremetadata).

Only a writer can call this method.

## Parameters

### `pbstrRestoreMetadata` [out]

A string containing the restore metadata.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | The specified attribute does not have a value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

This method can be called at any time depending on the logic of a given writer.

The caller should free the memory held by the *pbstrRestoreMetadata* parameter by calling
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

If no backup metadata has been set,
[GetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupmetadata) returns S_FALSE.

A writer setting the restore method to VSS_RME_RESTORE_TO_ALTERNATE_LOCATION without defining an alternate
location mapping constitutes a writer error.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)