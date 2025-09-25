# UCMUCSI_DEVICE_CONFIG_INIT function

## Description

Initializes a [**UCMUCSI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/ns-ucmucsidevice-_ucmucsi_device_config) structure.

## Parameters

### `Config`

A pointer to the **UCMUCSI_DEVICE_CONFIG** structure to initialize.

## Remarks

The client driver must call this initialization function before calling [**UcmUcsiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/nf-ucmucsidevice-ucmucsideviceinitialize).

## See also

[**EVT_WDF_DRIVER_DEVICE_ADD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[**UCMUCSI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsidevice/ns-ucmucsidevice-_ucmucsi_device_config)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)