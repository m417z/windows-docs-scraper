# WdfFdoInitSetEventCallbacks function

## Description

[Applies to KMDF only]

The **WdfFdoInitSetEventCallbacks** method registers a framework-based function driver's event callback functions, for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure that the driver obtained from its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

### `FdoEventCallbacks` [in]

A pointer to a driver-allocated [WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks) structure.

## Remarks

Before calling **WdfFdoInitSetEventCallbacks**, the driver must allocate a [WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks) structure and fill in the structure with pointers to the driver's event callback functions.

The driver must call **WdfFdoInitSetEventCallbacks** before calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about the **WdfFdoInitSetEventCallbacks** method, see [Creating Device Objects in a Function Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-device-objects-in-a-function-driver).

#### Examples

The following code example initializes a WDF_FDO_EVENT_CALLBACKS structure and then calls **WdfFdoInitSetEventCallbacks**.

```cpp
WDF_FDO_EVENT_CALLBACKS fdoCallbacks;

WDF_FDO_EVENT_CALLBACKS_INIT(&fdoCallbacks);
fdoCallbacks.EvtDeviceFilterAddResourceRequirements = MyEvtDeviceFilterAddResourceRequirements;
fdoCallbacks.EvtDeviceFilterRemoveResourceRequirements = MyEvtDeviceFilterRemoveResourceRequirements;
fdoCallbacks.EvtDeviceRemoveAddedResources = MyEvtDeviceRemoveAddedResources;

WdfFdoInitSetEventCallbacks(
                            DeviceInit,
                            &fdoCallbacks
                            );
```

## See also

[WDF_FDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdf_fdo_event_callbacks_init)