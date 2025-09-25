# IVssComponent::SetRestoreMetadata

## Description

The
**SetRestoreMetadata** method sets writer-specific metadata for the current component.

Only a writer can call this method, and only in the context of implementing
[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore).

## Parameters

### `wszRestoreMetadata` [in]

A caller-allocated **NULL**-terminated wide character string containing the restore metadata for the component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_ALREADY_EXISTS** | Private metadata has already been written for this component. |
| **VSS_E_BAD_STATE** | The method was called outside of the context of a writer handling a [PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event. |

## Remarks

**IVssComponent::SetRestoreMetadata** sets private, writer-specific metadata, which can be used by a writer during a restore operation.

The format need not conform to any VSS metadata specification.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoremetadata)

[IVssComponent::SetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupmetadata)