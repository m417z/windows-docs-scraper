## Description

Gets the Wi-Fi adapter type.

## Parameters

### `Adapter`

[_In_] A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

## Return value

Returns a [**WIFI_ADAPTER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_type) object that defines the Wi-Fi adapter type.

## Remarks

If the client driver needs to query the adapter type from the NETADAPTER_INIT object before the adapter is created, call [**WifiAdapterInitGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitgettype) instead.

For a code example that uses **WifiAdapterGetType** during adapter creation, see [Event callback for adapter creation](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#event-callback-for-adapter-creation).

## See also

[**WifiAdapterInitGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitgettype)

[**WIFI_ADAPTER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_type)