# NetDeviceInitConfig function

## Description

The **NetDeviceInitConfig** function initializes device initialization operations when the Plug and Play (PnP) manager reports the existence of a device.

## Parameters

### `DeviceInit` [_Inout_]

A pointer to a WDFDEVICE_INIT object that the client driver received in its [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) routine.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

A client driver calls this function in its [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback before it calls [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

When a client driver calls **NetDeviceInitConfig**, the system-supplied NetAdapterCx.sys driver calls the following functions on behalf of the client. The client driver should not call these functions directly. Doing so may result in undefined behavior.

- [**WdfDeviceInitSetReleaseHardwareOrderOnFailure**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetreleasehardwareorderonfailure)
- [**WdfDeviceInitSetDeviceType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetdevicetype)
- [**WdfDeviceInitSetCharacteristics**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetcharacteristics)
- [**WdfDeviceInitSetIoType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype)
- [**WdfDeviceInitSetPowerPageable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable)

## See also

[*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)