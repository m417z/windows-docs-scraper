# IVssBackupComponentsEx::SetSelectedForRestoreEx

## Description

The
**SetSelectedForRestoreEx** method indicates whether the specified selectable component is selected for restoration to a specified writer instance.

## Parameters

### `writerId` [in]

Globally unique identifier (GUID) of the writer class.

### `ct` [in]

Type of the component. See [VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)
for the possible values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component.
For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the
component was added.

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component.

The string cannot be **NULL** and should contain the same component name as was used when the component was added
to the backup set using
the [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent) method.

### `bSelectedForRestore` [in]

If the value of this parameter is **true**, the selected component has been selected for restoration. If the
value is **false**, the selected component has not been selected for restoration.

### `instanceId` [in]

GUID of the writer instance.

The default value for this parameter is GUID_NULL.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully indicated that the specified component has been selected to be restored. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The component being selected does not exist in the Backup Components Document, or a live instance of the writer corresponding to that component is not running on the system. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**SetSelectedForRestoreEx**, which moves a component to a different writer instance, can be called only for a writer that supports running multiple writer instances with the same class ID and supports a requester moving a component to a different writer instance at restore time. To determine whether a writer provides this support, call the [IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema) method.

**SetSelectedForRestoreEx** has
meaning only for restores taking place in component mode.

**SetSelectedForRestoreEx** can
be called only for components that were explicitly added to the backup document at backup time using
[AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).
Restoring a component that was implicitly selected for backup as part of a component set must be done by calling
**SetSelectedForRestoreEx** on the
closest ancestor component that was added to the document. If only this component's data is to be restored, that
should be accomplished through
the [IVssBackupComponents::AddRestoreSubcomponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addrestoresubcomponent) method;
this can be done only if the component is selectable for restore (see
[Working with Selectability and
Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths)).

This method must be called before
the [IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) method.

The distinction between the *instanceId* and *writerID* parameters is necessary because it is possible that multiple instances of the same writer are running on the computer.

If the value of the *instanceId* parameter is GUID_NULL, this is equivalent to calling the [IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore) method.

The *instanceId* parameter is used to specify that the component is to be restored to a different writer instance. If the value of the *instanceId* parameter is not GUID_NULL, it must match the instance ID of a writer instance with the same writer class ID specified in the *writerID* parameter.

A writer's class identifier, instance identifier, and instance name can be found by calling the [IVssExamineWriterMetadataEx::GetIdentityEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex-getidentityex) method.

## See also

[IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore)

[IVssBackupComponentsEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponentsex)

[IVssExamineWriterMetadata::GetBackupSchema](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getbackupschema)

[IVssExamineWriterMetadataEx::GetIdentityEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadataex-getidentityex)