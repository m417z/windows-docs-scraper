# IVssBackupComponents::AddComponent

## Description

The **AddComponent** method is
used to explicitly add to the backup set in the Backup Components Document all required
components (nonselectable for backup components without a selectable for backup ancestor), and such optional
(selectable for backup) components as the requester considers necessary. Members of component sets (components
with a selectable for backup ancestor) are implicitly included in the backup set, but are not explicitly added to
the Backup Components Document.

## Parameters

### `instanceId` [in]

Identifies a specific instance of a writer.

### `writerId` [in]

Writer class identifier.

### `ct` [in]

Identifies the type of the component. Refer to the documentation for
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for permitted input values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the selectable for backup component.
For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

A logical path is not required when adding a component. Therefore, the value of this parameter can be
**NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the selectable for backup component.

The value of this parameter cannot be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_ALREADY_EXISTS** | The object is a duplicate. A component with the same logical path and component name already exists. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The **AddComponent** method has meaning only if the backup operation takes place in component mode.

Only these kinds of components should be added to the Backup Components Document using **AddComponent**.
- Components that are selectable for backup (see [selectability for backup](https://learn.microsoft.com/windows/win32/vss/vssgloss-s)).
- Nonselectable-for-backup components with no selectable-for-backup ancestors.

Nonselectable for backup components that have a selectable for backup ancestor in the hierarchy of their
logical paths are part of a component set defined by the selectable for backup ancestor. These components are
implicitly added to the Backup Components Document when the ancestor is added and should never be explicitly added
to a requester's Backup Components Document by using
**AddComponent**.The result of doing so is
undefined (see [Working with
Selectability and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths)).

Selectable for backup components with selectable for backup ancestors are also subcomponents in a component
set. They can be implicitly selected if their ancestor is selected (in which case they are not added to the Backup
Components Document using
**AddComponent**), or they can be
explicitly selected using
**AddComponent**.

The combination of logical path and name for each component of a given instance of a given class of writer
must be unique. Attempting to call
**AddComponent** twice with the same values
of *wszLogicalPath* and *wszComponentName* results in a
VSS_E_OBJECT_ALREADY_EXISTS error.

The distinction between the *instanceId* and the *writerID* is
necessary because it is possible to run multiple copies for the same writer.

A writer's class identifier and instance can be found by calling
[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity).

Before it calls **AddComponent**, a
requester must have been initialized for backup by calling
[IVssBackupComponents::InitializeForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforbackup) and [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata). See [Overview of Backup Initialization](https://learn.microsoft.com/windows/desktop/VSS/overview-of-backup-initialization).

The requester must call **AddComponent** to add the required components to the shadow copy before calling [IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset) to create the shadow copy. See [Overview of the Backup Discovery Phase](https://learn.microsoft.com/windows/desktop/VSS/overview-of-the-backup-discovery-phase) and [Overview of Pre-Backup Tasks](https://learn.microsoft.com/windows/desktop/VSS/overview-of-pre-backup-tasks).

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)

[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)