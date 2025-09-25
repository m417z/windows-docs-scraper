# CmRegisterCallbackEx function

## Description

The **CmRegisterCallbackEx** routine registers a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine.

## Parameters

### `Function` [in]

A pointer to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine to register.

### `Altitude` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. This structure must contain a string that represents the [altitude](https://learn.microsoft.com/windows-hardware/drivers/ifs/load-order-groups-and-altitudes-for-minifilter-drivers) of the calling [minifilter driver](https://learn.microsoft.com/windows-hardware/drivers/ifs/file-system-minifilter-drivers). For more information, see Remarks.

### `Driver` [in]

A pointer to the [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure that represents the driver.

### `Context` [in, optional]

A driver-defined value that the configuration manager will pass as the *CallbackContext* parameter to the *RegistryCallback* routine.

### `Cookie` [out]

A pointer to a LARGE_INTEGER variable that receives the value that identifies the callback routine. When you unregister the callback routine, pass this value as the *Cookie* parameter to [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback).

### `Reserved`

This parameter is reserved for future use.

## Return value

**CmRegisterCallbackEx** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) values:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_INSTANCE_ALTITUDE_COLLISION** | The calling driver or another driver has already registered a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine for the specified altitude. |
| **STATUS_INSUFFICIENT_RESOURCES** | An attempt to allocate memory failed. |

## Remarks

The **CmRegisterCallbackEx** routine is available starting with Windows Vista.

A driver can call [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or **CmRegisterCallbackEx** to register a [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine, which is called every time a thread performs an operation on the registry.

The *Altitude* parameter defines the position of the minifilter driver relative to other minifilters in the I/O stack when the minifilter is loaded. Allocation of altitudes to minifilters is managed by Microsoft. For more information about altitudes, see [Load Order Groups and Altitudes for Minifilter Drivers](https://learn.microsoft.com/windows-hardware/drivers/ifs/load-order-groups-and-altitudes-for-minifilter-drivers).

Call [CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback) to unregister a callback routine that **CmRegisterCallbackEx** registered.

For more information about **CmRegisterCallbackEx** and filtering registry operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmUnRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmunregistercallback)

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)