# IVssCreateExpressWriterMetadata::SetBackupSchema

## Description

Used by an express writer to indicate in its Writer Metadata Document the types of backup operations it can participate in.

## Parameters

### `dwSchemaMask` [in]

A bitmask of
[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema) enumeration values that specify the types of backup operations this writer supports.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the failure message. |
| **E_INVALIDARG** | The backup schema argument is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

If no schema is explicitly set by
**SetBackupSchema**, the express writer will be assigned the default value of **VSS_BS_UNDEFINED**. **VSS_BS_UNDEFINED** means that the writer supports only simple full backup and restoration of entire files (as defined by **VSS_BT_FULL**), there is no support for incremental or differential backups, and partial files are not supported. Only the **VSS_BS_UNDEFINED**, **VSS_BS_COPY** and **VSS_BS_INDEPENDENT_SYSTEM_STATE** backup schema types are supported by express writers.

Requesters call
[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema) to retrieve a writer's backup schemas as set by
**SetBackupSchema**.

## See also

[IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata)