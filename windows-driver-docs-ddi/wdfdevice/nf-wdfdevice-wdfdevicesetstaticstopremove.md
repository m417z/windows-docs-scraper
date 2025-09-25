# WdfDeviceSetStaticStopRemove function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetStaticStopRemove** method informs the framework whether a device can be stopped and removed.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Stoppable` [in]

A Boolean value that indicates whether the specified device can be stopped and removed. If **TRUE**, the device can be stopped and removed. If **FALSE**, the device cannot be stopped and removed.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

By default, a device can be stopped and removed. Therefore, a driver typically calls **WdfDeviceSetStaticStopRemove** only if it must temporarily set the *Stoppable* parameter to **FALSE**. For example, a driver that controls a DVD writer might call **WdfDeviceSetStaticStopRemove** with *Stoppable* set to **FALSE** before it begins burning a DVD. After the driver has finished burning the DVD, it would call **WdfDeviceSetStaticStopRemove** again with *Stoppable* set to **TRUE**.

If your driver's device is supporting a special file (see [WdfDeviceSetSpecialFileSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetspecialfilesupport)), the framework will not allow the device to be stopped or removed. In this case, your driver does not have to call **WdfDeviceSetStaticStopRemove** .

The driver must match every call to **WdfDeviceSetStaticStopRemove** with *Stoppable* set to **FALSE** with a call to **WdfDeviceSetStaticStopRemove** with *Stoppable* set to **TRUE**.

Calling **WdfDeviceSetStaticStopRemove** with *Stoppable* set to **FALSE** does not prevent the framework from notifying the driver if the device is unexpectedly removed (surprise-removed).

For more information about how to prevent the operating system from stopping a device, see [Handling Requests to Stop a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-requests-to-stop-a-device).

#### Examples

The following code example informs the framework that the specified device cannot be stopped and removed.

```cpp
WdfDeviceSetStaticStopRemove(
                             device,
                             FALSE
                             );
```