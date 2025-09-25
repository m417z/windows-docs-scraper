## Description

A WiFiCx client driver calls the **WifiAdapterInitGetType** function when it needs to query the adapter type from the NETADAPTER_INIT object before the adapter is created.

## Parameters

### `AdapterInit`

[_In_] A pointer to a caller-provided NETADAPTER_INIT object.

## Return value

Returns a [**WIFI_ADAPTER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_type) object that defines the Wi-Fi adapter type.

## Remarks

## See also

[**WifiAdapterGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadaptergettype)

[**WIFI_ADAPTER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_type)