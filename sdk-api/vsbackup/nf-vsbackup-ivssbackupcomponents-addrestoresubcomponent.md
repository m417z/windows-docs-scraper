# IVssBackupComponents::AddRestoreSubcomponent

## Description

The **AddRestoreSubcomponent**
method indicates that a subcomponent member of a component set, which had been marked as nonselectable
for backup but is marked selectable for restore, is to be restored irrespective of whether any other
member of the component set will be restored.

## Parameters

### `writerId` [in]

Writer class identifier.

### `componentType` [in]

Identifies the type of the component. Refer to the documentation for
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for possible return values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component in the backup document
that defines the backup component set containing the subcomponent to be added for restore.

The value of this parameter can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the logical path of the component in the backup document
that defines the backup component set containing the subcomponent to be added for restore.

The value of this parameter cannot be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** component name.

### `wszSubComponentLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the subcomponent to be added for
restore.

A logical path is required when adding a subcomponent. Therefore, the value of this parameter cannot be
**NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszSubComponentName` [in]

**Null**-terminated wide character string containing the logical name of the subcomponent to be added for
restore.

The value of this parameter cannot be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** component name.

### `bRepair` [in]

This parameter is reserved for future use. This parameter should always be set to **false**

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the restore subcomponent. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has not been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The component does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Before calling
**AddRestoreSubcomponent**, the
root component defined by the *wszLogicalPath* and
*wszComponentName* parameters must first be selected for restore using
[IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore).

If a requester is to support restoring subcomponents, this method must be called before
[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore).

**AddRestoreSubcomponent**
is intended for the case in which all the files in a writer's component set must be backed up as a unit, but where
it is desirable that selected files (subcomponents) be capable of being restored individually.

To participate in such a restore, a subcomponent must have the
**bSelectableForRestore** member of
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) set to **TRUE**. The component defined
by the *wszLogicalPath* and *wszComponentName* parameters must
also be selected for restore using
[IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore).

See [Working with
Selectability for Restore and Subcomponents](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-for-restore-and-subcomponents) for more information.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)