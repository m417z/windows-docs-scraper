## Description

The **WifiAdapterInitialize** function initializes a newly created NETADAPTER object for WiFiCx.

## Parameters

### `Adapter`

[_In_] A handle to a NetAdapterCx NETADAPTER object obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

This function might return failure in low resource situations.

## Remarks

The client driver must call this function from within [*EvtWifiDeviceCreateAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter).

For more information, see [Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver).

## See also

[**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate)

[*EvtWifiDeviceCreateAdapter*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nc-wificx-evt_wifi_device_create_adapter)

[Writing a WiFiCx client driver](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver)