# WdfIoTargetGetState function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetGetState** method returns state information for a local or remote I/O target.

## Parameters

### `IoTarget` [in]

A handle to a local or remote I/O target object that was obtained from a previous call to [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) or [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate) or from a method that a specialized I/O target supplies.

## Return value

**WdfIoTargetGetState** returns a [WDF_IO_TARGET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_state)-typed value that indicates the state of the specified I/O target.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about **WdfIoTargetGetState**, see [Controlling a General I/O Target's State](https://learn.microsoft.com/windows-hardware/drivers/wdf/controlling-a-general-i-o-target-s-state).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example obtains state information for a USB I/O target.

```cpp
WDF_IO_TARGET_STATE  ioTargetState;

ioTargetState = WdfIoTargetGetState(WdfUsbTargetPipeGetIoTarget(pipeHandle));
```

## See also

[WDF_IO_TARGET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_state)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)