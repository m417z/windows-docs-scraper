# IVssCreateExpressWriterMetadata::AddComponent

## Description

Adds a
file group to an express writer's set of components to be backed up.

## Parameters

### `ct` [in]

A [VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) enumeration value that specifies
the type of the component. Only **VSS_CT_FILEGROUP** is supported for this parameter.

### `wszLogicalPath` [in]

A pointer to a **null**-terminated wide character string containing the logical path of the database or file group.
For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

This parameter is optional and can be **NULL**.

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

This parameter is optional and can be **NULL**.

### `cbIcon` [in]

The size, in bytes, of the buffer. If
the *pbIcon* parameter is **NULL**,
*cbIcon* must be zero.

### `bRestoreMetadata` [in]

This parameter is reserved for future use and should always be set to **false**.

### `bNotifyOnBackupComplete` [in]

This parameter is reserved for future use and should always be set to **false**.

### `bSelectable` [in]

A Boolean value that indicates whether the component can be optionally backed up (which means it can be excluded
from the backup) or is always backed up when any of the writer's components is backed up. This parameter should be set to
**true** if the component can be selectively backed up, or **false** if the component is backed up when any of the components
is backed up.

### `bSelectableForRestore` [in]

A Boolean value that determines whether a component can be individually restored when it has not been
[explicitly included](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-e) in
the backup document. If the component was explicitly added to the backup document, it can always be
individually selected for restore; in this case, this flag has no meaning.

When this parameter is **true**, the component can be restored by itself; when **false**, the component can be restored only if
the entire component set is being restored. (For more information, see
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) and
[Working with Selectability
and Logical Paths](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-and-logical-paths).)

The default value for this parameter is **false**.

### `dwComponentFlags` [in]

A bitmask of [VSS_COMPONENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_flags) enumeration values indicating the features that this component supports.
This bitmask cannot include **VSS_CF_APP_ROLLBACK_RECOVERY** or **VSS_CF_BACKUP_RECOVERY**.

The default value for this parameter is zero.

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

This method can be called multiple times to add several components to an express writer's metadata.

The combination of logical path and name for each component of a specified instance of a specified class of writer
must be unique. Attempting to call
**AddComponent** twice with
the same values of *wszLogicalPath* and *wszComponentName* results
in a VSS_E_OBJECT_ALREADY_EXISTS error.

**AddComponent** can be used to
add subcomponents—components in which all member files are backed up as a group but which contain
files that can be restored individually. For more information, see
[Working with
Selectability for Restore and Subcomponents](https://learn.microsoft.com/windows/desktop/VSS/working-with-selectability-for-restore-and-subcomponents).

## See also

[IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata)