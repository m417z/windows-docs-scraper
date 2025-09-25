# WdfDeviceIndicateWakeStatus function

## Description

[Applies to KMDF only]

The **WdfDeviceIndicateWakeStatus** method informs the framework that the calling bus driver has stopped waiting for a specified device to trigger a wake signal on the bus.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `WaitWakeStatus` [in]

An NTSTATUS status value. If the device triggered a wake signal, the caller must set this value to STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*WaitWakeStatus*) equals **TRUE**. If the device did not trigger a wake signal or if an error was detected, the caller must provide a status value for which NT_SUCCESS(*WaitWakeStatus*) equals **FALSE**. For more information, see the following Remarks section.

## Return value

If the operation succeeds, **WdfDeviceIndicateWakeStatus** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | *WaitWakeStatus* is STATUS_PENDING or STATUS_CANCELLED. |
| **STATUS_INVALID_DEVICE_REQUEST** | The driver stack was not set up to wait for the device to trigger a wake signal. |
| **STATUS_INVALID_DEVICE_STATE** | The calling driver is not responsible for waiting for the device to trigger a wake signal. |

The method might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*WaitWakeStatus*) equals **TRUE**, the framework will restore the device and system to their working states. If NT_SUCCESS(*WaitWakeStatus*) equals **FALSE**, the device and system will remain in their current states.

For more information about calling the **WdfDeviceIndicateWakeStatus** method, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

#### Examples

The following code example informs the framework that the specified device has triggered a wake signal.

```cpp
NTSTATUS  status;

status = WdfDeviceIndicateWakeStatus(
                                     hChild,
                                     STATUS_SUCCESS
                                     );
```