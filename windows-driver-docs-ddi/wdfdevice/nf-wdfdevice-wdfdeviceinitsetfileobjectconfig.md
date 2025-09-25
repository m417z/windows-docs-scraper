# WdfDeviceInitSetFileObjectConfig function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetFileObjectConfig** method registers event callback functions and sets configuration information for the driver's framework file objects.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `FileObjectConfig` [in]

A pointer to a caller-allocated [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.

### `FileObjectAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied object attributes for the driver's framework file objects. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

## Remarks

If a driver calls **WdfDeviceInitSetFileObjectConfig**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

By default, each framework file object inherits its synchronization scope and execution level from its parent device object. If the parent device object's synchronization scope and execution level are not **WdfSynchronizationScopeNone** and **WdfExecutionLevelPassive**, the driver must set the **WdfSynchronizationScopeNone** and **WdfExecutionLevelPassive** values in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that the *FileObjectAttributes* parameter specifies. Otherwise, [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) will return an error status code. For more information about synchronization scope and execution level, see [Using Automatic Synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-automatic-synchronization).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about framework file objects, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects)

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and a [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure and then calls **WdfDeviceInitSetFileObjectConfig**.

```cpp
WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.SynchronizationScope = WdfSynchronizationScopeNone;
WDF_FILEOBJECT_CONFIG_INIT(
                           &deviceConfig,
                           MyEvtDeviceFileCreate,
                           MyEvtFileClose,
                           WDF_NO_EVENT_CALLBACK // No cleanup callback function
                           );
WdfDeviceInitSetFileObjectConfig(
                                 DeviceInit,
                                 &deviceConfig,
                                 &attributes
                                 );
```

## See also

[WDF_FILEOBJECT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_fileobject_config_init)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks)

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)