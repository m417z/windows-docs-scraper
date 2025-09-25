# UcmUcsiDeviceInitialize function

## Description

Initializes the UCSI extension (UcmUcsiCx).

## Parameters

### `WdfDevice`

A handle to a framework device object that the client driver received in a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config`

A pointer to a caller-supplied [**UCMUCSI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/ns-ucmucsidevice-_ucmucsi_device_config) structure that is initialized by calling [**UCMUCSI_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/nf-ucmucsidevice-ucmucsi_device_config_init).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code.

## Remarks

The client driver must call **UcmUcsiDeviceInitialize** in the driver's [**EVT_WDF_DRIVER_DEVICE_ADD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) implementation after calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) successfully.

## See also

[**EVT_WDF_DRIVER_DEVICE_ADD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**UCMUCSI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/ns-ucmucsidevice-_ucmucsi_device_config)

[**UCMUCSI_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/nf-ucmucsidevice-ucmucsi_device_config_init)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)