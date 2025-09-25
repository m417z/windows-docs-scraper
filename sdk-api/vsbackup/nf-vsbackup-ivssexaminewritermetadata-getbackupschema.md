# IVssExamineWriterMetadata::GetBackupSchema

## Description

The
**GetBackupSchema** method is used by a requester to determine from the Writer Metadata Document the types of backup operations that a given writer can participate in.

## Parameters

### `pdwSchemaMask`

The types of backup operations that a given writer supports, expressed as a bit mask (or bitwise OR) of
[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema) enumeration values.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the failure message. |
| **E_INVALIDARG** | The backup schema argument is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

The default backup schema is VSS_BS_UNDEFINED: the writer supports only simple full backup and restoration of entire files (as defined by VSS_BT_FULL), there is no support for incremental or differential backups, and partial files are not supported.

The writer calls
[IVssCreateWriterMetadata::SetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setbackupschema) to indicate its supported schema in its Writer Metadata Document.

## See also

[IVssCreateWriterMetadata::SetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setbackupschema)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)