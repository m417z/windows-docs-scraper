# WdfDeviceSetFailed function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetFailed** method informs the framework that the driver encountered a hardware or software error that is associated with a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `FailedAction` [in]

A [WDF_DEVICE_FAILED_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_failed_action)-typed enumerator that indicates whether the framework should attempt to reload the specified device's drivers.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If a driver encounters an unrecoverable hardware or software error, it must call **WdfDeviceSetFailed** so that the system can unload the device's drivers.

Starting in UMDF version 2.15, a UMDF driver can request that the underlying bus driver re-enumerate it by calling **WdfDeviceSetFailed** with *FailedAction* set to **WdfDeviceFailedAttemptRestart**. The bus driver must support the [GUID_REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff546570(v=vs.85)) interface.

Alternatively, a UMDF driver can set *FailedAction* to **WdfDeviceFailedNoRestart**.

For more information about **WdfDeviceSetFailed**, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

#### Examples

The following code example informs the framework that a failure has occurred. If the specified device's drivers are not supporting other devices, the framework will unload the drivers and then attempt to reload them.

```cpp
WdfDeviceSetFailed(
                   device,
                   WdfDeviceFailedAttemptRestart
                   );
```