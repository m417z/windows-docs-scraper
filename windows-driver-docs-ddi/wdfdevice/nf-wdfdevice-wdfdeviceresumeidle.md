# WdfDeviceResumeIdle macro

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceResumeIdle** method informs the framework that the specified device is not in use and can be placed in a device low-power state if it remains idle.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Every call to [WdfDeviceStopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle) must eventually be followed by a call to **WdfDeviceResumeIdle**, or else the device will never return to a low-power state if it again becomes idle.

Calling [WdfDeviceResumeIdleWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdeviceresumeidlewithtag) instead of **WdfDeviceResumeIdle** provides additional information (tag value, line number, and file name) that you can view in Microsoft debuggers.

#### Examples

The following code example informs the framework that the specified device is not in use and can be placed in a device low-power state if it remains idle.

```cpp
WdfDeviceResumeIdle(device);
```

## See also

[Debugging Power Reference Leaks in WDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-power-reference-leaks-in-wdf)

[WdfDeviceResumeIdleWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdeviceresumeidlewithtag)

[WdfDeviceStopIdle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle)

[WdfDeviceStopIdleWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevicestopidlewithtag)