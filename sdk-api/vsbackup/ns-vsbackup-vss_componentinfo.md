# VSS_COMPONENTINFO structure

## Description

The **VSS_COMPONENTINFO** structure contains
information about a given component, and is returned to requesters by the
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) interface.

## Members

### `type`

Component type. See [VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type).

### `bstrLogicalPath`

A string containing the logical path of the component.

A logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `bstrComponentName`

A string containing the name of the component. A component name string cannot be **NULL**.

### `bstrCaption`

A string containing the description of the component. A caption string can be **NULL**.

### `pbIcon`

Pointer to a buffer containing the binary data for a displayable icon representing the component. The
buffer contents should use the same format as the standard icon (.ico) files. The size, in bytes, of the buffer
is specified by **cbIcon**.

If the writer that created the component did not choose to specify an icon, **pbIcon**
is **NULL**.

### `cbIcon`

The size, in bytes, of the displayable icon (**pbIcon**) representing the component.
If **pbIcon** is **NULL**, **cbIcon** should
be zero.

### `bRestoreMetadata`

Boolean that indicates whether there is private metadata associated with the restoration of the component.
The Boolean is **true** if there is metadata and **false** if there
is not.

A writer indicates whether a component supports private metadata by setting this value when a component is
added with
[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent).
Writers later add restore metadata with
[IVssComponent::SetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setrestoremetadata).
Requesters retrieve the information using
[IVssComponent::GetRestoreMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getrestoremetadata).

### `bNotifyOnBackupComplete`

Reserved for future use. The value of this parameter should always be set to
**false**.

### `bSelectable`

Boolean that indicates (for component mode operations) if the component is selectable for backup. The value
of **bSelectable** helps determine whether a requester has the option of including or
excluding a given component in backup operations. The Boolean is **true** if the component
is selectable for backup and **false** if it is not.

There is no default value for a component's selectability for backup. A writer must always explicitly set the
value when it adds the component to its Writer Metadata Document using
[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent).

In addition, the value of **bSelectable**, the component's logical path, and the
component's relationship to other components as expressed in that path determine when and how a component is
included in a backup operation:

* For a nonselectable for backup component (**bSelectable** is
  **false**) with no selectable for backup ancestors in the hierarchy of its logical path,
  inclusion in the backup set is always mandatory and always implicit.
  A requester explicitly adds the component to the backup set in the Backup Components Document with
  [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).
* For a selectable for backup component (**bSelectable** is
  **true**) with no selectable for backup ancestor in the hierarchy of its logical paths,
  inclusion in the backup set is always optional and always explicit.
  A requester explicitly adds the component to the backup set in the Backup Components Document with
  [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

  If such a component is included as an ancestor in the logical path of other components, both those that are
  selectable for backup and those that are not, it defines a component set containing these other components as
  subcomponents. If a selectable for backup component is explicitly included in a backup, these subcomponents
  are implicitly included in the backup.
* For a nonselectable for backup component (**bSelectable** is
  **false**) that has a selectable for backup ancestor in the hierarchy of its logical
  paths (and are therefore part of a component set defined by that ancestor), inclusion in the backup set is
  always implicit and contingent on the inclusion of a selectable for backup ancestor.
  A requester never explicitly adds the component to the backup set in the Backup Components Document;
  instead, it adds the selectable for backup ancestor to the document using
  [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).
* For a selectable for backup component (**bSelectable** is
  **true**) that has a selectable for backup ancestor in the hierarchy of its logical
  paths (and is therefore part of a component set defined by that ancestor), inclusion in the backup set can be
  either optional and explicit, or if the component is not explicitly selected, its inclusion may be implicit
  and contingent on the inclusion of a selectable for backup ancestor.
  If the inclusion of the component is explicit, a requester explicitly adds the components to the backup set
  in the Backup Components Document with
  [IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

  If the inclusion is implicit, a requester does not add these components to a backup set in the Backup
  Components Document.

  If the inclusion of the component is explicit and the component defines a component set, the members of
  that component set are implicitly selected.

  A writer sets a component's selectability for backup (**bSelectable**) when adding
  the component to the Writer Metadata Document by using
  [IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent).

  See [Working with Selectability
  and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for more information.

### `bSelectableForRestore`

Boolean that indicates (for component-mode operations) whether the component is selectable for restore.
**bSelectableForRestore** allows the requester to determine whether this component can be
individually selected for restore if it had earlier been
[implicitly included](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-i) in the
backup. The Boolean is **true** if the component is selectable for restore and
**false** if it is not.

By default, a component's selectability for restore is **false**. A writer can override
this default when it adds the component to its Writer Metadata Document using
[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent).

If a component is explicitly added to the backup document (see [explicit component inclusion](https://learn.microsoft.com/windows/win32/vss/vssgloss-e)), then it can always be individually selected for restore; so this flag then has no meaning. If a component is implicitly added to the backup document, then the
**bSelectableForRestore** flag determines whether the component can be individually
restored using
[IVssBackupComponents::AddRestoreSubcomponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addrestoresubcomponent).

See [Working with Selectability
and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for more information.

### `dwComponentFlags`

A bit mask (or bitwise OR) of values of the
[VSS_COMPONENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_flags) enumeration, indicating the
features this component supports.

**Windows Server 2003 and Windows XP:** Before Windows Server 2003 with SP1, this member is reserved for system use.

### `cFileCount`

If the component is a file group, the number of file descriptors for files in the group. Otherwise, this
value is zero.

### `cDatabases`

If the component is a database, the number of database file descriptors. Otherwise, this value is
zero.

### `cLogFiles`

If the component is a database, the number of database log file descriptors. Otherwise, the value of this
parameter is zero.

### `cDependencies`

The number of explicit writer-component dependencies of the current component. This value is incremented
when
[IVssCreateWriterMetadata::AddComponentDependency](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponentdependency)
is called by a writer.

## Remarks

To obtain **VSS_COMPONENTINFO** object for a given
component, a requester must first obtain the corresponding
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) object through a call to
[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent).
A call to
[IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo) then
allocates and returns a **VSS_COMPONENTINFO**
structure.

Because **VSS_COMPONENTINFO** is allocated and
returned by
[IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo),
a requester should not free a **VSS_COMPONENTINFO** object
directly, but should use
[IVssWMComponent::FreeComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-freecomponentinfo).

## See also

[IVssCreateWriterMetadata::AddComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-addcomponent)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent)

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)

[IVssWMComponent::FreeComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-freecomponentinfo)

[IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)