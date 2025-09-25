## Description

The **WifiDirectDeviceInitialize** function initializes a newly created WIFIDIRECTDEVICE object.

## Parameters

### `WifiDirectDevice`

[_In_] A handle to a WIFIDIRECTDEVICE object obtained in a previous call to [**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client calls **WifiDirectDeviceInitialize** from within its [*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice) routine.

For a code example of creating a WIFIDIRECTDEVICE object, see [Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities).

## See also

[Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities)

[*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice)

[**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate)