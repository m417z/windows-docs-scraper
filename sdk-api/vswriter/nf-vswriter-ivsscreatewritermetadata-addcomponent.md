# IVssCreateWriterMetadata::AddComponent

## Description

The **AddComponent** method adds a
database or file group as a component to be backed up.

## Parameters

### `ct` [in]

A [VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) enumeration value specifying
the type of the component.

**Windows Server 2003 and Windows XP:** Before Windows Server 2003 with SP1, this parameter is reserved for system use, and the caller should not override the default value.

### `wszLogicalPath` [in]

A pointer to a **null**-terminated wide character string containing the logical path of the database or file group.
For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

A logical path is optional and can be **NULL**.

### `wszComponentName` [in]

A pointer to a **null**-terminated wide character string containing the name of the component. This string is not localized.

This parameter is required and cannot be **NULL**. The string cannot contain backslashes.

### `wszCaption` [in]

A pointer to a **null**-terminated wide character string containing a description (also called a "friendly name") for the component.
This string might be localized, and therefore requesters must assume that it is localized.

This parameter is optional and can be **NULL**. The string can contain backslashes.

### `pbIcon` [in]

A pointer to a bitmap of the icon representing the database, to be displayed in a user interface.
The size, in bytes, of the buffer is specified by the *cbIcon* parameter.

If the writer does not want to specify an icon, *pbIcon* should be set to **NULL**.

### `cbIcon` [in]

The size, in bytes, of the buffer. If
the *pbIcon* parameter is **NULL**,
*cbIcon* should be zero.

### `bRestoreMetadata` [in]

This parameter is reserved for future use and should always be set to **false**.

### `bNotifyOnBackupComplete` [in]

This parameter is reserved for future use and should always be set to **false**.

### `bSelectable` [in]

A Boolean that indicates whether the component can be optionally backed up (which means it can be excluded
from the backup) or is always backed up when any of the writer's component is backed up. The Boolean is
**true** if the component can be selectively backed up and **false** if it is backed up when any of the components
is backed up.

### `bSelectableForRestore` [in]

A Boolean that determines whether a component can be individually restored when it has not been
[explicitly included](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-e) in
the backup document. If the component was explicitly added to the backup document, it can always be
individually selected for restore; in this case, this flag has no meaning.

When **true**, the component can be restored by itself; when **false**, the component can be restored only if
the entire component set is being restored. (See
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) and
[Working with Selectability
and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths) for more information).

The default value for this parameter is **false**.

### `dwComponentFlags` [in]

A bit mask (or bitwise OR) of members of the
[VSS_COMPONENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_flags) enumeration indicating the features that this component supports.

The default value for this argument is zero.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_ALREADY_EXISTS** | The object is a duplicate. A component with the same logical path and component name already exists. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

This method can be called multiple times to add several components to a writer's metadata.

The combination of logical path and name for each component of a given instance of a given class of writer
must be unique. Attempting to call
**AddComponent** twice with
the same values of *wszLogicalPath* and *wszComponentName* results
in a VSS_E_OBJECT_ALREADY_EXISTS error.

**AddComponent** can be used to
add subcomponents—components in which all member files are backed up as a group, but which contain
files that can be restored individually. See
[Working with
Selectability for Restore and Subcomponents](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-for-restore-and-subcomponents) for more information.

## See also

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)