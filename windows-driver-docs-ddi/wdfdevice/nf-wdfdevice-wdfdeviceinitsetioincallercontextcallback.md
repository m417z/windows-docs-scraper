# WdfDeviceInitSetIoInCallerContextCallback function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetIoInCallerContextCallback** method registers a driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) event callback function.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `EvtIoInCallerContext` [in]

A pointer to the driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) callback function.

## Remarks

If a driver calls **WdfDeviceInitSetIoInCallerContextCallback**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about the [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) event callback function, see [Intercepting an I/O Request before it is Queued](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-i-o-queues).

#### Examples

The following code example registers a driver's [EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context) event callback function.

```cpp
WdfDeviceInitSetIoInCallerContextCallback(
                                          DeviceInit,
                                          MyEvtIoInCallerContext
                                          );
```

## See also

[EvtIoInCallerContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_io_in_caller_context)