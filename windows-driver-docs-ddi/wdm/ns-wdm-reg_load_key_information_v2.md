## Description

The **REG_LOAD_KEY_INFORMATION_V2** structure contains information about a registry hive that is being loaded.

## Members

### `Object`

A pointer to the registry key object for the root key of the hive that is about to be loaded.

### `KeyName`

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the root key.

### `SourceFile`

A pointer to a **UNICODE_STRING** structure that contains the path name of a file that contains the registry hive information that is being loaded.

### `Flags`

Reserved for system use.

### `TrustClassObject`

Reserved for system use.

### `UserEvent`

A pointer to an event object that is signaled when the hive is unloaded.

### `DesiredAccess`

The access mask that was specified by the thread that is trying to load the registry key. For more information about this access mask, see the description of the *DesiredAccess* parameter of the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) routine.

### `RootHandle`

An optional pointer to a location that receives the handle to the root of the hive that is being loaded. This member can be non-**NULL** if an application hive is being loaded. In all other cases, this member should be **NULL**.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling the [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext) routine.

### `Version`

A pointer to a numeric version identifier of REG_LOAD_KEY_INFORMATION_*.

### `FileAccessToken`

A pointer to an access token (PACCESS_TOKEN) that impersonates its access level when accessing a file (this for security purposes). In this case, it is used when accessing the hive file being loaded into the registry.

## Remarks

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls)

[RegLoadKey](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regloadkeya)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[REG_LOAD_KEY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reg_load_key_information)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)