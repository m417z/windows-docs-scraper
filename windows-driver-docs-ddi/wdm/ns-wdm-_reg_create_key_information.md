## Description

Obsolete. Starting with Windows 7, use [**REG_CREATE_KEY_INFORMATION_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1), the V1 version of this structure instead.

The **REG_CREATE_KEY_INFORMATION** structure contains information that a driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can use when a registry key that is being created.

## Members

### `CompleteName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the path of the new registry key. The path can be absolute or relative. If the path is absolute, this structure contains a fully qualified path that starts with the "\\" character. For an absolute path, the **RootObject** member specifies the **\REGISTRY** key, which is the root directory of the registry tree. If the path is relative, the path starts with a character other than "\\", and is relative to the key that is specified by the *RootObject* member.

### `RootObject`

Pointer to the registry key object that serves as the root for the path specified by the *CompleteName* member.

### `ObjectType`

The **ObjectType** member is reserved for internal use. Drivers must not access this member.

### `CreateOptions`

A bitwise OR of flags. For more information about these flags, see the *CreateOptions* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine.

### `Class`

A pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that identifies the key's object class. For more information about this member, see the *Class* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine.

### `SecurityDescriptor`

A pointer to a [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that contains security information for the key object.

### `SecurityQualityOfService`

A pointer to a **SECURITY_QUALITY_OF_SERVICE** structure, which is defined in Winnt.h.

### `DesiredAccess`

The access mask that was specified by the thread that is attempting to create the registry key.

### `GrantedAccess`

An access mask that indicates the access rights that have been granted to the thread that is attempting to create the registry key. For more information about this member, see Remarks.

### `Disposition`

A value that indicates whether the registry key was created. For more information about this member, see the *Disposition* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine and the following Remarks section.

### `ResultObject`

A pointer to a location that receives the address of the key object that represents the created registry key. For more information about this member, see Remarks.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply.

### `RootObjectContext`

A pointer to a driver-defined context information that the driver has associated with the root of the path for the registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext).

### `Transaction`

A pointer to a transaction object that the operation is attempted on. If this member is **NULL**, the operation is being performed in non-transactional context.

### `Reserved`

If this member is 1, then it is safe to cast this structure to type [REG_CREATE_KEY_INFORMATION_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1), which contains additional parameters.

## Remarks

The configuration manager passes this structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to create a key—for example, when a user-mode thread calls **RegCreateKey** or **RegCreateKeyEx** or when a driver calls [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey).

If the driver's *RegistryCallback* routine returns STATUS_CALLBACK_BYPASS for a **RegNtPreCreateKeyEx** notification, the driver must supply the **GrantedAccess**, **Disposition**, and **ResultObject** values.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[**REG_CREATE_KEY_INFORMATION_V1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_create_key_information_v1)

[**REG_POST_OPERATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_post_operation_information)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)