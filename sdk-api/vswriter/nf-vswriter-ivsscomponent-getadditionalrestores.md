# IVssComponent::GetAdditionalRestores

## Description

The
**GetAdditionalRestores** method is used by a writer during incremental or differential restore operations to determine whether a given component will require additional restore operations to completely retrieve it.

Either a writer or a requester can call this method.

## Parameters

### `pbAdditionalRestores` [out]

The address of a caller-allocated variable that receives **true** if additional restores will occur for the current component, or **false** otherwise.

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

The value returned by
**GetAdditionalRestores** will be false, unless during a restore operation a requester calls
[IVssBackupComponents::SetAdditionalRestores](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setadditionalrestores).

**GetAdditionalRestores** should be used to check if it is necessary to use more than one backup set to completely restore a component. A component might first be retrieved by restoring data from a full backup, and then updating that data from one or more subsequent incremental or differential backups.

The
**GetAdditionalRestores** method is typically used by writers that support an explicit recovery mechanism as part of their
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event handler ([CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore))—for instance, the Exchange Server, and database applications such as SQL Server. For these applications, it is often not possible to perform additional differential, incremental, or log restores after such a recovery is performed.

Therefore, if
**GetAdditionalRestores** returns **true** for a component, such a writer should not execute its explicit recovery mechanism and should expect that additional differential, incremental, or log restores will be done.

When
[SetAdditionalRestores](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setadditionalrestores) returns **false**, then after the restore has finished, when handling the
[PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore) event, the writer can complete its recovery operation and be brought back online.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)