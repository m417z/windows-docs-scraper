# WdfDeviceInitSetReleaseHardwareOrderOnFailure function

## Description

[Applies to KMDF and UMDF]

 The **WdfDeviceInitSetReleaseHardwareOrderOnFailure** method specifies whether the framework calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function immediately after device failure, or waits until all child devices have been removed.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `ReleaseHardwareOrderOnFailure` [in]

A [WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_release_hardware_order_on_failure)-typed enumerator that specifies when the framework calls the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function.

## Remarks

Typically, the framework calls a driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function after it has called the *EvtDeviceReleaseHardware* function for all child devices that the driver enumerates.

In the event of a device power-up or power-down failure, however, the framework might call the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) before it has called the *EvtDeviceReleaseHardware* functions for all child devices.

To override this default behavior, a driver can call **WdfDeviceInitSetReleaseHardwareOrderOnFailure** to specify that, even in device failure scenarios, the framework should always wait to call its [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) function until it has called the *EvtDeviceReleaseHardware* functions of the child devices.

 For example, a bus driver that performs hardware access on behalf of its child devices could use this technique to ensure that its child devices do not request access to hardware after the framework has called the bus driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function.

If a driver calls **WdfDeviceInitSetReleaseHardwareOrderOnFailure**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example shows how a bus driver can request that the framework wait to call its [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) callback function until all of its child devices have been removed.

```cpp
WdfDeviceInitSetReleaseHardwareOrderOnFailure(
                       DeviceInit,
                       WdfReleaseHardwareOrderOnFailureAfterDescendants
                       );
```

## See also

[EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_RELEASE_HARDWARE_ORDER_ON_FAILURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_release_hardware_order_on_failure)