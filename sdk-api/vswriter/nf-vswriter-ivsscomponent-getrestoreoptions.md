# IVssComponent::GetRestoreOptions

## Description

The
**GetRestoreOptions** method gets the restore options specified to the current writer by a requester using
[IVssBackupComponents::SetRestoreOptions](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestoreoptions).

Either a writer or a requester can call this method.

## Parameters

### `pbstrRestoreOptions` [out]

String containing the restore options of the writer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **S_FALSE** | No restore options have been specified. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

The caller should free the memory held by the *pbstrRestoreOptions* parameter by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

If no restore options have been set, S_FALSE is returned.

## See also

[IVssBackupComponents::SetRestoreOptions](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestoreoptions)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetBackupOptions](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupoptions)