## Description

Gets the Wi-Fi Direct port ID.

## Parameters

### `WifiDirectDevice`

[_In_] A handle to a WIFIDIRECTDEVICE object obtained in a previous call to [**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate).

## Return value

Returns the Wi-Fi Direct port ID.

## Remarks

The client calls **WifiDirectDeviceGetPortId** from within its [*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice) routine.

For a code example of creating a WIFIDIRECTDEVICE object, see [Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities).

## See also

[**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate)

[*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice)

[Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities)