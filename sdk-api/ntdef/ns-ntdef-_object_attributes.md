# _OBJECT_ATTRIBUTES structure

## Description

The **OBJECT_ATTRIBUTES** structure specifies attributes that can be applied to objects or object handles by routines that create objects and/or return handles to objects.

## Members

### `Length`

The number of bytes of data contained in this structure. The [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro sets this member to **sizeof**(**OBJECT_ATTRIBUTES**).

### `RootDirectory`

Optional handle to the root object directory for the path name specified by the *ObjectName* member. If *RootDirectory* is `NULL`, *ObjectName* must point to a fully qualified object name that includes the full path to the target object. If *RootDirectory* is non-`NULL`, *ObjectName* specifies an object name relative to the *RootDirectory* directory. The *RootDirectory* handle can refer to a file system directory or an object directory in the object manager namespace.

### `ObjectName`

Pointer to a [Unicode string](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) that contains the name of the object for which a handle is to be opened. This must either be a fully qualified object name, or a relative path name to the directory specified by the *RootDirectory* member.

### `Attributes`

Bitmask of flags that specify object handle attributes. This member can contain one or more of the flags in the following table.

| Flag | Meaning |
|------|---------|
| OBJ_INHERIT | This handle can be inherited by child processes of the current process. |
| OBJ_PERMANENT | This flag only applies to objects that are named within the object manager. By default, such objects are deleted when all open handles to them are closed. If this flag is specified, the object is not deleted when all open handles are closed. Drivers can use the [ZwMakeTemporaryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwmaketemporaryobject) routine to make a permanent object non-permanent. |
| OBJ_EXCLUSIVE | If this flag is set and the **OBJECT_ATTRIBUTES** structure is passed to a routine that creates an object, the object can be accessed exclusively. That is, once a process opens such a handle to the object, no other processes can open handles to this object.<br><br>If this flag is set and the **OBJECT_ATTRIBUTES** structure is passed to a routine that creates an object handle, the caller is requesting exclusive access to the object for the process context that the handle was created in. This request can be granted only if the **OBJ_EXCLUSIVE** flag was set when the object was created.
| OBJ_CASE_INSENSITIVE | If this flag is specified, a case-insensitive comparison is used when matching the name pointed to by the **ObjectName** member against the names of existing objects. Otherwise, object names are compared using the default system settings. |
| OBJ_OPENIF | If this flag is specified, by using the object handle, to a routine that creates objects and if that object already exists, the routine should open that object. Otherwise, the routine creating the object returns an NTSTATUS code of **STATUS_OBJECT_NAME_COLLISION**. |
| OBJ_OPENLINK | If an object handle, with this flag set, is passed to a routine that opens objects and if the object is a symbolic link object, the routine should open the symbolic link object itself, rather than the object that the symbolic link refers to (which is the default behavior). |
| OBJ_KERNEL_HANDLE | The handle is created in system process context and can only be accessed from kernel mode. |
| OBJ_FORCE_ACCESS_CHECK | The routine that opens the handle should enforce all access checks for the object, even if the handle is being opened in kernel mode. |
| OBJ_DONT_REPARSE | If this flag is set, no reparse points will be followed when parsing the name of the associated object. If any reparses are encountered the attempt will fail and return an **STATUS_REPARSE_POINT_ENCOUNTERED** result. This can be used to determine if there are any reparse points in the object's path, in security scenarios. |
| OBJ_IGNORE_IMPERSONATED_DEVICEMAP | A device map is a mapping between DOS device names and devices in the system, and is used when resolving DOS names. Separate device maps exists for each user in the system, and users can manage their own device maps. Typically during impersonation, the impersonated user's device map would be used. However, when this flag is set, the process user's device map is used instead. |
| OBJ_VALID_ATTRIBUTES | Reserved. |

### `SecurityDescriptor`

Specifies a security descriptor ([SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_security_descriptor)) for the object when the object is created. If *SecurityDescriptor* is `NULL`, the object will receive default security settings. See [DACL for a New Object](https://learn.microsoft.com/windows/win32/secauthz/dacl-for-a-new-object).

### `SecurityQualityOfService`

Optional quality of service to be applied to the object when it is created. Used to indicate the security impersonation level and context tracking mode (dynamic or static). Currently, the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro sets this member to `NULL`.

## Remarks

Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro to initialize the members of the **OBJECT_ATTRIBUTES** structure. Note that **InitializeObjectAttributes** initializes the *SecurityQualityOfService* member to `NULL`. If you must specify a non-`NULL` value, set the *SecurityQualityOfService* member after initialization.

To apply the attributes contained in this structure to an object or object handle, pass a pointer to this structure to a routine that accesses objects or returns object handles, such as [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ntcreatefile) or [ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatedirectoryobject).

All members of this structure are read-only. If a member of this structure is a pointer, the object that this member points to is read-only as well. Read-only members and objects can be used to acquire relevant information but must not be modified. To set the members of this structure, use the **InitializeObjectAttributes** macro.

Driver routines that run in a process context other than that of the system process must set the **OBJ_KERNEL_HANDLE** flag for the *Attributes* member (by using the **InitializeObjectAttributes** macro). This restricts the use of a handle opened for that object to processes running only in kernel mode. Otherwise, the handle can be accessed by the process in whose context the driver is running.

## See also

[FltCreateCommunicationPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatecommunicationport)

[FltCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatefile)

[FltCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatefileex)

[FltCreateFileEx2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltcreatefileex2)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatefile)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-iocreatefileex)

[IoCreateFileSpecifyDeviceObjectHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-iocreatefilespecifydeviceobjecthint)

[ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatedirectoryobject)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ntcreatefile)

[DACL for a New Object](https://learn.microsoft.com/windows/win32/secauthz/dacl-for-a-new-object)