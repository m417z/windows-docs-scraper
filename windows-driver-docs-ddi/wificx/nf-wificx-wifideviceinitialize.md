## Description

The **WifiDeviceInitialize** function registers the client driver's WiFiCx-specific callback functions.

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config`

[_In_] A pointer to a client driver-allocated and initialized [**WIFI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_config) structure.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client driver must call **WifiDeviceInitialize** from [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add), after calling [**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig) but before calling [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For an example of how to initialize a WifiCx device, see [Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver).

## See also

[Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver)

[**NetDeviceInitConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/nf-netdevice-netdeviceinitconfig)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[**WIFI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_config)