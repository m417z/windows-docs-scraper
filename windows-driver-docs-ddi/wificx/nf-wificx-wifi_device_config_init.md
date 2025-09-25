## Description

The **WIFI_DEVICE_CONFIG_INIT** function initializes the [**WIFI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_config) structure.

## Parameters

### `Config`

[_Out_] A pointer to the client driver-allocated [**WIFI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_config) structure.

### `WdiVersion`

[_In_] The WDI version.

### `SendCommand`

[_In_] A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_SEND_COMMAND*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function.

### `CreateAdapter`

[_In_] A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter) callback function.

### `CreateWifiDirectDevice`

[_In_] A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice) callback function.

## Remarks

The client driver calls this function from its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) event callback function in preparation for calling [**WiFiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize).

## See also

[Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver)

[**WIFI_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_device_config)

[*EVT_WIFI_DEVICE_SEND_COMMAND*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[*EVT_WIFI_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter)

[*EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice)

[**WiFiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize)