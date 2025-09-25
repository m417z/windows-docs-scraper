# IVssBackupComponentsEx2::SetRestoreName

## Description

Assigns a new logical name to a component that is being restored.

## Parameters

### `writerId` [in]

The globally unique identifier (GUID) of the writer class.

### `ct` [in]

The type of the component. See the [VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)
enumeration for the possible values.

### `wszLogicalPath` [in]

A **null**-terminated wide character string containing the logical path of the component.
For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as the string that was used when the
component was added.

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

A **null**-terminated wide character string containing the name of the component.

The string cannot be **NULL** and should contain the same component name as was the component name that was used when the component was added
to the backup set using
the [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent) method.

### `wszRestoreName` [in]

A **null**-terminated wide character string containing the restore name to be set for the component.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The restore name was successfully set. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | This method was not called during a restore operation. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component was not found. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The **SetRestoreName** method can only be called during a restore operation.

A writer indicates that it supports this method by setting the **VSS_BS_RESTORE_RENAME** flag in its backup schema mask.

For more
information, see [Setting VSS Restore
Options](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-options).

## See also

[IVssBackupComponentsEx2](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex2)

[IVssComponentEx::GetRestoreName](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponentex-getrestorename)

[VSS_BACKUP_SCHEMA](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_backup_schema)