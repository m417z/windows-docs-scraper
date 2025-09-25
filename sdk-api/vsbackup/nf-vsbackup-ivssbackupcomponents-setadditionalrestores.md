# IVssBackupComponents::SetAdditionalRestores

## Description

The
**SetAdditionalRestores** method is used by a requester during incremental or differential restore operations to indicate to writers that a given component will require additional restore operations to completely retrieve it.

## Parameters

### `writerId` [in]

Writer identifier.

### `ct` [in]

Type of the component. See
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for the possible values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component to be added.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component.

The value of the string should not be **NULL**, and should contain the same component as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

### `bAdditionalRestores` [in]

If the value of this parameter is **true**, additional restores of the component will follow this restore. If the value is **false**, additional restores of the component will not follow this restore.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the additional restore status. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The backup component does not exist. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The information provided by the
**SetAdditionalRestores** method is typically used by writers that support an explicit recovery mechanism as part of their
PostRestore event handler ([CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore))—for instance, the Exchange Server, and database applications such as SQL Server. For these applications, it is often not possible to perform additional differential, incremental, or log restores after such a recovery is performed.

Therefore, if
**SetAdditionalRestores** for a component is set to **true**, this means that such a writer should not execute its explicit recovery mechanism and should expect that additional differential, incremental, or log restores will be done.

When
**SetAdditionalRestores** on a component is set to **false**, then after the component is restored, the application can complete its recovery operation and be brought back online.

This method must be called before
[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore).

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)