# IVssComponent::SetBackupMetadata

## Description

The
**SetBackupMetadata** method sets backup
metadata with the component.

A writer can call this method only during a backup operation.

This method cannot be called while handling a
[BackupComplete](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) ([CVssWriter::OnBackupComplete](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupcomplete)) or
[BackupShutdown](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-b) ([CVssWriter::OnBackupShutdown](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onbackupshutdown)) event.

## Parameters

### `wszData` [in]

A **NULL**-terminated wide character string that contains the backup metadata.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_ALREADY_EXISTS** | Private metadata has already been written for this component. |
| **VSS_E_BAD_STATE** | This method was not called by a writer or, if called by a writer, it either was not called during a backup operation or was called while handling a BackupComplete or BackupShutdown event. |

## Remarks

**SetBackupMetadata** sets
private, writer-specific metadata describing a backup operation.

The format need not conform to any VSS metadata specification.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetBackupMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getbackupmetadata)

[IVssComponent::SetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoremetadata)