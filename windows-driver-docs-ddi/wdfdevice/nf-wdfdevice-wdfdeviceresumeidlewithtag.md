# WdfDeviceResumeIdleWithTag macro

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceResumeIdleWithTag** macro decrements the power reference count for a specified framework device object and assigns the driver's current file name and line number to the reference. The macro also assigns a tag value to the reference.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Tag` [in]

A driver-defined value that the framework stores as an identification tag for the power reference.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If the object's reference count becomes zero, the object might be deleted before **WdfDeviceResumeIdleWithTag** returns.

Calling **WdfDeviceResumeIdleWithTag** instead of [**WdfDeviceResumeIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidle) provides additional information (tag value, line number, and file name) that you can view in Microsoft debuggers. **WdfDeviceResumeIdleWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the [**!wdfkd.wdftagtracker**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdftagtracker) debugger extension.

Use [**!wdfkd.wdfdevice**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdfdevice) with verbose flags on and locate the link to [**!wdftagtracker**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdftagtracker) in the output:

```cpp
kd> !wdfdevice <handle> f
```

## See also

[Debugging Power Reference Leaks in WDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-power-reference-leaks-in-wdf)

[**WdfDeviceResumeIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidle)

[**WdfDeviceStopIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle)

[**WdfDeviceStopIdleWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidlewithtag)