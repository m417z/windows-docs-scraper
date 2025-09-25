# InitializeObjectAttributes macro

## Description

The **InitializeObjectAttributes** macro initializes the opaque [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure, which specifies the properties of an object handle to routines that open handles.

## Parameters

### `p`

A pointer to the [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure to initialize.

### `n`

A pointer to a Unicode string that contains the name of the object for which a handle is to be opened. This must either be a fully qualified object name, or a relative path name to the object directory specified by the RootDirectory parameter.

### `a`

Specifies one or more of the following flags:

|Flag|Description|
|---|---|
|OBJ_INHERIT |This handle can be inherited by child processes of the current process.|
|OBJ_PERMANENT|This flag only applies to objects that are named within the object manager. By default, such objects are deleted when all open handles to them are closed. If this flag is specified, the object is not deleted when all open handles are closed. Drivers can use ZwMakeTemporaryObject to delete permanent objects.|
|OBJ_EXCLUSIVE|Only a single handle can be open for this object.|
|OBJ_CASE_INSENSITIVE|If this flag is specified, a case-insensitive comparison is used when matching the ObjectName parameter against the names of existing objects. Otherwise, object names are compared using the default system settings.|
|OBJ_OPENIF|If this flag is specified to a routine that creates objects, and that object already exists then the routine should open that object. Otherwise, the routine creating the object returns an NTSTATUS code of STATUS_OBJECT_NAME_COLLISION.|
|OBJ_KERNEL_HANDLE|Specifies that the handle can only be accessed in kernel mode.|
|OBJ_FORCE_ACCESS_CHECK | The routine opening the handle should enforce all access checks for the object, even if the handle is being opened in kernel mode.|

### `r`

A handle to the root object directory for the path name specified in the ObjectName parameter. If ObjectName is a fully qualified object name, RootDirectory is NULL. Use [ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatedirectoryobject) to obtain a handle to an object directory.

### `s`

Specifies a security descriptor to apply to an object when it is created. This parameter is optional. Drivers can specify NULL to accept the default security for the object. For more information, see the following Remarks section.

## Syntax

```cpp
VOID InitializeObjectAttributes(
  [out]          POBJECT_ATTRIBUTES   p,
  [in]           PUNICODE_STRING      n,
  [in]           ULONG                a,
  [in]           HANDLE               r,
  [in, optional] PSECURITY_DESCRIPTOR s
);
```

## Remarks

**InitializeObjectAttributes** initializes an [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wudfwdm/ns-wudfwdm-_object_attributes) structure that specifies the properties of an object handle to be opened. The caller can then pass a pointer to this structure to a routine that actually opens the handle.

Driver routines that run in a process context other than that of the system process must set the OBJ_KERNEL_HANDLE flag for the *Attributes* parameter. This flag restricts the use of a handle opened for that object to processes running only in kernel mode. Otherwise, the handle can be accessed by the process in whose context the driver is running.

Note that **InitializeObjectAttributes** always sets the **SecurityQualityOfService** member of [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wudfwdm/ns-wudfwdm-_object_attributes) to **NULL**. Drivers that require a non-**NULL** value can set **SecurityQualityOfService** directly.

## See also

[ExCreateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-excreatecallback)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-iocreatefile)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wudfwdm/ns-wudfwdm-_object_attributes)

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-pscreatesystemthread)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_security_descriptor)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwCreateDirectoryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatedirectoryobject)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ntcreatefile)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwcreatekey)

[ZwMakeTemporaryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwmaketemporaryobject)

[ZwOpenFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ntopenfile)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwopenkey)

[ZwOpenSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwopensection)

[ZwOpenSymbolicLinkObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-zwopensymboliclinkobject)