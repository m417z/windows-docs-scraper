# WdfDriverCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfDriverCreate** method creates a framework driver object for the calling driver.

## Parameters

### `DriverObject` [in]

A pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure that represents a Windows Driver Model (WDM) driver object. The driver receives this pointer as input to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

### `RegistryPath` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the registry path string that the driver received as input to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

### `DriverAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure. (The structure's **ParentObject** member must be **NULL**.) This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `DriverConfig` [in]

A pointer to a caller-allocated [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure.

### `Driver` [out, optional]

A pointer to a location that receives a handle to the new framework driver object. This parameter is optional and can be WDF_NO_HANDLE.

## Return value

**WdfDriverCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_DRIVER_INTERNAL_ERROR** | The driver called [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) more than once. |
| **STATUS_INVALID_PARAMETER** | A [non-Plug and Play (PnP) driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-kernel-mode-driver-framework-with-non-pnp-drivers) specified an [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. |

For more information about return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the *DriverObject*, *RegistryPath*, or *DriverConfig* parameter is **NULL**.

## Remarks

A driver that uses Kernel-Mode Driver Framework must call **WdfDriverCreate** from within its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, before calling any other framework routines. For more information about **DriverEntry**, see **DriverEntry for Framework-based Drivers**.

Before your driver calls **WdfDriverCreate**, the driver must call [WDF_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_config_init) to initialize its [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure.

The framework driver object is the top of your driver's tree of framework objects and therefore does not have a parent object.

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the driver object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

#### Examples

The following code example is a [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine that initializes a WDF_DRIVER_CONFIG structure and then creates a framework driver object.

```cpp
NTSTATUS
DriverEntry(
    IN PDRIVER_OBJECT  DriverObject,
    IN PUNICODE_STRING  RegistryPath
    )
{
    WDF_DRIVER_CONFIG  config;
    NTSTATUS  status = STATUS_SUCCESS;

    WDF_DRIVER_CONFIG_INIT(
                           &config,
                           MyEvtDeviceAdd
                           );
    config.EvtDriverUnload = MyEvtDriverUnload;
    status = WdfDriverCreate(
                             DriverObject,
                             RegistryPath,
                             WDF_NO_OBJECT_ATTRIBUTES,
                              &config,
                             WDF_NO_HANDLE
                             );
    if (!NT_SUCCESS(status)) {
        TraceEvents(
                    TRACE_LEVEL_ERROR,
                    DBG_PNP,
                    "WdfDriverCreate failed with status %!STATUS!",
                    status
                    );
    }
    return status;
}
```

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config)

[WDF_DRIVER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdf_driver_config_init)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)