# _REG_CREATE_KEY_INFORMATION_V1 structure

## Description

The **REG_CREATE_KEY_INFORMATION_V1** structure contains information that a filter driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use when a registry key is being created.

## Members

### `CompleteName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path of the new registry key. The path can be absolute or relative. If the path is absolute, this structure contains a fully qualified path that starts with the "\\" character. For an absolute path, the **RootObject** member specifies the **\REGISTRY** key, which is the root directory of the registry tree. If the path is relative, the path starts with a character other than "\\", and is relative to the key that is specified by the **RootObject** member.

### `RootObject`

A pointer to a registry key object that represents the root registry key for the path that is specified by the **CompleteName** member.

### `ObjectType`

This member is reserved for use by the operating system. Drivers must not access this member.

### `Options`

Specifies the options for the key-create routine to use to create or open the new key. For more information, see the description of the *CreateOptions* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine and the description of the *OpenOptions* parameter of the [ZwOpenKeyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkeyex) routine.

### `Class`

A pointer to a **UNICODE_STRING** structure that identifies the object class of the new key. For more information about this member, see the *Class* parameter of the **ZwCreateKey** routine. This pointer value can be **NULL**.

### `SecurityDescriptor`

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that contains security information for the key object. This pointer was obtained from the **SecurityDescriptor** member of the [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that was passed as an input parameter in the call to create the new registry key.

### `SecurityQualityOfService`

A pointer to a [SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_quality_of_service) structure. This structure indicates whether a server can impersonate the client that is trying to create the registry key, and, if impersonation is permitted, the extent to which it is permitted.

### `DesiredAccess`

The access mask that was specified by the thread that is trying to create the registry key. For more information about this access mask, see the description of the *DesiredAccess* parameter of the **ZwCreateKey** routine.

### `GrantedAccess`

An access mask that indicates the access rights that were granted to the thread that is trying to create the registry key. For more information about this member, see the following Remarks section.

### `Disposition`

A value that indicates whether the requested registry operation will create a new key or open an existing one. For more information about this member, see the description of the *Disposition* parameter of the **ZwCreateKey** routine and the following Remarks section.

### `ResultObject`

A pointer to a location that receives the address of the key object that represents the created registry key.

### `CallContext`

Optional driver-defined context information that the driver's *RegistryCallback* routine can supply.

### `RootObjectContext`

A pointer to driver-defined context information that the driver has associated with the root of the path of the registry object by calling the [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext) routine.

### `Transaction`

A pointer to a transaction object for the registry operation. You can supply this pointer to the [ObOpenObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obopenobjectbypointer) routine to obtain the corresponding transaction handle. If this member is **NULL**, the operation is being performed in non-transactional context.

### `Version`

The structure version number. This member distinguishes the [REG_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information) structure in Windows Vista from the **REG_CREATE_KEY_INFORMATION_V1** structure in Windows 7 and later versions of Windows. The following version numbers are currently defined.

| Version number | Version of structure |
| --- | --- |
| 0 | **REG_CREATE_KEY_INFORMATION** |
| 1 | **REG_CREATE_KEY_INFORMATION_V1** |

Future versions of this structure might add new members but will not change the members that are already defined in existing versions of the structure. This member is defined in the **REG_CREATE_KEY_INFORMATION_V1** structure that is supported in Windows 7 and later versions of the Windows operating systems. In the **REG_CREATE_KEY_INFORMATION** structure that Windows Vista supports, this member is named **Reserved** and is set to zero. Filter drivers should rely on the version number and not the operating system version to determine which version of the structure they are using.

### `RemainingName`

A pointer to a **UNICODE_STRING** structure that contains the relative path of the new registry key. This member always expresses the path of the new key relative to the path of the key that is specified by the **RootObject** member. In contrast, the **CompleteName** member can contain an absolute path if the **RootObject** member specifies the **\REGISTRY** key.

### `Wow64Flags`

Contains the Wow64 flags from the access mask that was passed as an input parameter in the call to create the new registry key. This member indicates whether a 32-bit client program that is running on a 64-bit version of Windows is trying to create a registry key. This member is set to zero or to one of the following flag bits:

* KEY_WOW64_32KEY
* KEY_WOW64_64KEY

These flag bits are defined in the Wdm.h and Winnt.h header files. For more information about these flags, see [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/win32/sysinfo/registry-key-security-and-access-rights).

### `Attributes`

Contains the object-attribute flags from the **Attributes** member of the **OBJECT_ATTRIBUTES** structure that was passed as an input parameter in the call to create the new registry key. This member might contain one or more of the following flag bits:

* OBJ_KERNEL_HANDLE
* OBJ_FORCE_ACCESS_CHECK
* OBJ_OPENLINK

For more information about these flags, see [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes).

### `CheckAccessMode`

Indicates how the configuration manager performs the security access check for the call to create the new key. This member contains one of the following MODE enumeration values from the Wdm.h header file:

* **KernelMode**
* **UserMode**

This security check is similar to that performed by the [SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck) routine, which has an *AccessMode* parameter that can be set to either **UserMode** or **KernelMode**. If **CheckAccessMode** is set to **UserMode**, the configuration manager performs a full security access check regardless of whether the call originated in user mode or kernel mode. For more information about how to force user-mode security access checks on a call that originates in kernel mode, see the description of the OBJ_FORCE_ACCESS_CHECK flag in the **Attributes** member of the **OBJECT_ATTRIBUTES** structure.

## Remarks

The configuration manager passes this structure to the *RegistryCallback* routine every time that a thread tries to create a key—for example, when a user-mode thread calls [RegCreateKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeya) or [RegCreateKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeyexa), or when a kernel-mode driver calls [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey).

This structure is an extended version of the [REG_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information) structure that Windows Vista supports. The first 14 members, **CompleteName** through **Transaction**, are identical in the two structures. The last five members of the **REG_CREATE_KEY_INFORMATION_V1** structure, **Version** through **CheckAccessMode**, are not part of the **REG_CREATE_KEY_INFORMATION** structure.

If the driver's *RegistryCallback* routine returns STATUS_CALLBACK_BYPASS for a **RegNtPreCreateKeyEx** notification, the driver must supply the values for the **GrantedAccess**, **Disposition**, and **ResultObject** members.

The **REG_CREATE_KEY_INFORMATION_V1** structure is one of a number of structures that a filter driver can receive through its *RegistryCallback* routine. For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[ObOpenObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obopenobjectbypointer)

[REG_CREATE_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information)

[RegCreateKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeya)

[RegCreateKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeyexa)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_quality_of_service)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)