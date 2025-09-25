## Description

The **WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES_INIT** function initializes a [**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a driver-allocated [**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities) structure.

## Remarks

This function zeroes out the memory of the [**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities) structure, fills in the **Size** member, and sets the **Enabled** member to **TRUE**.

Call [**WifiAdapterPowerOffloadSetRsnRekeyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterpoweroffloadsetrsnrekeycapabilities) to set the net adapter's RSN rekey power offload capabilities.

## See also

[**WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_power_offload_rsn_rekey_capabilities)

[**WifiAdapterPowerOffloadSetRsnRekeyCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterpoweroffloadsetrsnrekeycapabilities)