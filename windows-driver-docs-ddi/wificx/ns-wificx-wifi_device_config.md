## Description

The **WIFI_DEVICE_CONFIG** structure contains pointers to a client driver's WiFiCx-specific callback functions. The client driver must supply an initialized **WIFI_DEVICE_CONFIG** structure as an input parameter to [**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize).

## Members

### `Size`

The size of this **WIFI_DEVICE_CONFIG** structure, in bytes.

### `WdiVersion`

The WDI version.

### `SendCommand`

A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_SEND_COMMAND*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command) callback function.

### `CreateAdapter`

A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter) callback function.

### `CreateWifiDirectDevice`

A pointer to the client driver's implementation of the [*EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice) callback function.

## Remarks

Call [**WIFI_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_config_init) to initialize this structure.

## See also

[**WifiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize)

[*EVT_WIFI_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter)

[*EVT_WIFI_DEVICE_SEND_COMMAND*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_send_command)

[*EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice)

[**WIFI_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_device_config_init)