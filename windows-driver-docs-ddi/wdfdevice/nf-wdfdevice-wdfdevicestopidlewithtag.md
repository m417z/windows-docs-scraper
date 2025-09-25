# WdfDeviceStopIdleWithTag macro

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceStopIdleWithTag** macro increments the power reference count for a specified framework device object and assigns the driver's current file name and line number to the reference. The macro also assigns a tag value to the reference.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `WaitForD0` [in]

A Boolean value that indicates when **WdfDeviceStopIdleWithTag** will return. If **TRUE**, it returns only after the specified device has entered the D0 device power state. If **FALSE**, the method returns immediately.

### `Tag` [in]

A driver-defined value that the framework stores as an identification tag for the power reference.

## Syntax

```cpp
NTSTATUS WdfDeviceStopIdleWithTag(
    _In_ WDFDEVICE Device,
    _In_ BOOLEAN WaitForD0,
    _In_ PVOID Tag
);
```

## Remarks

If the operation succeeds, **WdfDeviceStopIdleWithTag** returns STATUS_SUCCESS.

Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_PENDING** | The device is being powered up asynchronously. |
| **STATUS_INVALID_DEVICE_STATE** | The driver is not the power policy owner for the device. |
| **STATUS_POWER_STATE_INVALID** | A device failure occurred and the device cannot enter its D0 power state. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

If your driver calls **WdfDeviceStopIdleWithTag** to increment a reference count, the driver must call [**WdfDeviceResumeIdleWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidlewithtag) to decrement the count.

Calling **WdfDeviceStopIdleWithTag** instead of [**WdfDeviceStopIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle) provides additional information (tag value, line number, and file name) that you can view in Microsoft debuggers. **WdfDeviceStopIdleWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the [**!wdftagtracker**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdftagtracker) debugger extension. The debugger extension displays the tag value as both a pointer and a series of characters.

Use [**!wdfkd.wdfdevice**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdfdevice) with verbose flags on and locate the link to [**!wdftagtracker**](https://learn.microsoft.com/windows-hardware/drivers/debugger/-wdfkd-wdftagtracker) in the output:

```cpp
kd> !wdfdevice <handle> f
```

## See also

[Debugging Power Reference Leaks in WDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-power-reference-leaks-in-wdf)

[**WdfDeviceResumeIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidle)

[**WdfDeviceResumeIdleWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceresumeidlewithtag)

[**WdfDeviceStopIdle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicestopidle)