## Description

Creates a WIFIDIRECTDEVICE object.

## Parameters

### `WifiDirectDeviceInit`

[_In_] A pointer to a caller-allocated WIFIDIRECT_DEVICE_INIT object.

### `WifiDirectDeviceAttributes`

[_In__opt_] A pointer to a WDF_OBJECT_ATTRIBUTES object that contains driver-supplied attributes for the new WIFIDIRECTDEVICE object.

### `WifiDirectDevice`

[_Out_] A pointer to a location that receives a handle to the new WIFIDIRECTDEVICE object.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

The client calls **WifiDirectDeviceCreate** from within its [*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice) routine. Call [**WifiDirectDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdeviceinitialize) to initialize this object.

For a code example of creating a WIFIDIRECTDEVICE object, see [Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities).

## See also

[*EvtWifiDeviceCreateWifiDirectDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_wifidirectdevice)

[**WifiDirectDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdeviceinitialize)

[Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities)