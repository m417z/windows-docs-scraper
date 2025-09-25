## Description

WiFiCx client drivers implement *EvtWifiDeviceCreateWifiDirectDevice* to create a WIFIDIRECTDEVICE object.

## Parameters

### `Device`

[_In_] A handle to a framework device object that the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `WifiDirectDeviceInit`

[_Inout_] A pointer to a WIFIDIRECT_DEVICE_INIT object that describes the initialization information for the WIFIDIRECTDEVICE object.

## Return value

This callback function returns STATUS_SUCCESS if the operation was successful. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

A WiFiCx client driver registers the *EvtWifiDeviceCreateWifiDirectDevice* callback function by calling [**WiFiDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifideviceinitialize).

In its *EvtWifiDeviceCreateWifiDirectDevice* callback, the client driver:

- Calls [**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate) to create the WIFIDIRECTDEVICE object.
- Calls [**WifiDirectDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdeviceinitialize) to initialize the object.
- Calls [**WifiDirectDeviceGetPortId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicegetportid) to determine the port id (which is used in command messages).

For a code example of implementing *EvtWifiDeviceCreateWifiDirectDevice*, see [Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities).

## See also

[Wi-Fi Direct (P2P) Support](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#wi-fi-driect-device-capabilities)

[**WifiDirectDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicecreate)

[**WifiDirectDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdeviceinitialize)

[**WifiDirectDeviceGetPortId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifidirectdevicegetportid)