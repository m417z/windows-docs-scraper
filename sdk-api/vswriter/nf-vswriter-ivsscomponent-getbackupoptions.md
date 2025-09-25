# IVssComponent::GetBackupOptions

## Description

The
**GetBackupOptions** method returns the backup options specified to the writer that manages the currently selected component or component set by a requester using
[IVssBackupComponents::SetBackupOptions](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupoptions).

Either a writer or a requester can call this method.

## Parameters

### `pbstrBackupOptions` [out]

The address of a caller-allocated variable that receives a string containing the backup options for the current writer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | No backup options have been specified for this component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

If no backup options have been set, S_FALSE is returned.

If the call to **GetBackupOptions** is successful, the caller is responsible for freeing the string that is returned in the *pbstrBackupOptions* parameter by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## See also

[IVssBackupComponents::SetBackupOptions](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupoptions)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetRestoreOptions](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoreoptions)