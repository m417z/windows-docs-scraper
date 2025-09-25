# ZwOpenDirectoryObject function

## Description

The **ZwOpenDirectoryObject** routine opens an existing directory object.

## Parameters

### `DirectoryHandle` [out]

Handle for the newly opened directory object.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) structure specifying the requested types of access being requested for this directory object. A caller can specify one or a combination of the following.

| *DesiredAccess* Flags | Meaning |
| --- | --- |
| DIRECTORY_QUERY | Query access to the directory object |
| DIRECTORY_TRAVERSE | Name-lookup access to the directory object |
| DIRECTORY_CREATE_OBJECT | Name-creation access to the directory object |
| DIRECTORY_CREATE_SUBDIRECTORY | Subdirectory-creation access to the directory object |
| DIRECTORY_ALL_ACCESS | All of the preceding rights plus STANDARD_RIGHTS_REQUIRED. |

These requested access types are compared with the object's discretionary access-control list ([DACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)) to determine which accesses are granted or denied.

### `ObjectAttributes` [in]

Specified attributes for the directory object supplied by the caller. This parameter is initialized by calling the **InitializeObjectAttributes** macro.

## Return value

**ZwOpenDirectoryObject** returns STATUS_SUCCESS or an appropriate error status. The most common error status codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | A temporary buffer required by this routine could not be allocated. |
| **STATUS_INVALID_PARAMETER** | The specified *ObjectAttributes* parameter was a **NULL** pointer, not a valid pointer to an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure, or some of the fields specified in the OBJECT_ATTRIBUTES structure were invalid. |
| **STATUS_OBJECT_NAME_INVALID** | The *ObjectAttributes* parameter contained an **ObjectName** field in the **OBJECT_ATTRIBUTES** structure that was invalid because an empty string was found after the OBJECT_NAME_PATH_SEPARATOR character. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The *ObjectAttributes* parameter contained an **ObjectName** field in the **OBJECT_ATTRIBUTES** structure that could not be found. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The *ObjectAttributes* parameter contained an **ObjectName** field in the **OBJECT_ATTRIBUTES** structure with an object path that could not be found. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The *ObjectAttributes* parameter did not contain a **RootDirectory** field, but the **ObjectName** field in the **OBJECT_ATTRIBUTES** structure was an empty string or did not contain an OBJECT_NAME_PATH_SEPARATOR character. This indicates incorrect syntax for the object path. |

The **ZwOpenDirectoryObject** routine throws an exception if the *DirectoryHandle* parameter is an illegal pointer.

## Remarks

**ZwOpenDirectoryObject** opens an existing directory object and returns a handle to the object.

The **ZwOpenDirectoryObject** routine is called after the **InitializeObjectAttributes** macro is used to initialize specific attributes of the **OBJECT_ATTRIBUTES** structure for the object to be opened.

A directory object is created using the **ZwCreateDirectoryObject** routine**.** Any handle obtained by calling **ZwOpenDirectoryObject** must eventually be released by calling **ZwClose**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

**Note** If the call to the **ZwCreateDirectoryObject** function occurs in user mode, you should use the name "**NtCreateDirectoryObject**" instead of "**ZwCreateDirectoryObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatedirectoryobject)