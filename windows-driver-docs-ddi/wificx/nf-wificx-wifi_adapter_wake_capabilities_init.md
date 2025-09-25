## Description

The **WIFI_ADAPTER_WAKE_CAPABILITIES_INIT** method initializes a [**WIFI_ADAPTER_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_wake_capabilities) structure.

## Parameters

### `Capabilities`

[_Out_] A pointer to a driver-allocated [**WIFI_ADAPTER_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_wake_capabilities) structure.

## Remarks

This function zeroes out the memory of the **WIFI_ADAPTER_WAKE_CAPABILITIES** structure, then fills in the **Size** member. After calling this function, set the remaining members of the **WIFI_ADAPTER_WAKE_CAPABILITIES** structure according to your device's capabilities, then call [**WifiAdapterSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadaptersetwakecapabilities).

## See also

[**WIFI_ADAPTER_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_wake_capabilities)

[**WifiAdapterSetWakeCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadaptersetwakecapabilities)