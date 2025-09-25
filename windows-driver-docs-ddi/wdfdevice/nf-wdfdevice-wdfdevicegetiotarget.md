# WdfDeviceGetIoTarget function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceGetIoTarget** method returns a handle to a function or filter driver's [local I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets), for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the operation succeeds, **WdfDeviceGetIoTarget** returns a handle to a framework I/O target object. If the specified framework device object represents a PDO, the method returns **NULL**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

When a UMDF driver sends a driver-created request to a local I/O target, the request has no associated file object. Some lower targets, such as a HIDClass-enumerated raw PDO, fail requests that have no associated file object. In this situation, a UMDF driver can specify **WdfIoTargetOpenLocalTargetByFile** to create an I/O target that represents the lower stack (just like a local target) using a file handle. As a result, any driver-created requests sent to this I/O target are associated with the file object corresponding to the handle opened.

 To do so, call the [WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_file) function before calling [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example obtains a handle to a specified device's local I/O target.

```cpp
WDFIOTARGET  ioTargetHandle;

ioTargetHandle = WdfDeviceGetIoTarget(device);
```