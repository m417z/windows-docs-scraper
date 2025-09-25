# IVssCreateWriterMetadata::SetBackupSchema

## Description

The
**SetBackupSchema** method is used by a writer to indicate in its Writer Metadata Document the types of backup operations it can participate in.

## Parameters

### `dwSchemaMask` [in]

The types of backup operations this writer supports expressed as a bitmask of
[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema) enumeration values.

For express writers, only the **VSS_BS_UNDEFINED**, **VSS_BS_COPY**, and **VSS_BS_INDEPENDENT_SYSTEM_STATE** values are supported.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | Successfully set the failure message. |
| **E_INVALIDARG**<br><br>0x80070057L | The backup schema argument is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_NOT_SUPPORTED**<br><br>0x8004232FL | The caller specified a [VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema) value that is not supported for express writers. |

## Remarks

If no schema is explicitly set by
**SetBackupSchema**, the writer will be assigned the default value of VSS_BS_UNDEFINED: the writer supports only simple full backup and restoration of entire files (as defined by VSS_BT_FULL), there is no support for incremental or differential backups, and partial files are not supported.

Requesters call
[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema) to retrieve a writer's backup schemas as set by
**SetBackupSchema**.

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)

[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)