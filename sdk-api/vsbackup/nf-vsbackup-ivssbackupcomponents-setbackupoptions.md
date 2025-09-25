# IVssBackupComponents::SetBackupOptions

## Description

The
**SetBackupOptions** method sets a string of private, or writer-dependent, backup parameters for a component.

## Parameters

### `writerId` [in]

Writer identifier.

### `ct` [in]

Type of the component. See
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for the possible values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component.

The string containing the name cannot be **NULL** and should contain the same component name as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

### `wszBackupOptions` [in]

**Null**-terminated wide character string containing the backup parameters to be set.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the backup options. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The backup component does not exist. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The exact syntax and content of the backup options set by the *wszBackupOptions* parameter of the
**SetBackupOptions** method will depend on the specific writer being contacted.

This method must be called before
[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)

[IVssBackupComponents::SetRestoreOptions](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrestoreoptions)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)