## Description

The **WifiAdapterPowerOffloadSetRsnRekeyCapabilities** function sets a WiFiCx net adapter's RSN rekey power offload capabilities.

## Parameters

### `Adapter`

[_In_] A handle to a NetAdapterCx NETADAPTER object obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Capabilities`

[_In_] A pointer to a driver-allocated and initialized [**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities) structure.

## Remarks

The client driver typically calls this function from within [*EVT_DEVICE_PREPARE_HARDWARE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

## See also

[**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities)