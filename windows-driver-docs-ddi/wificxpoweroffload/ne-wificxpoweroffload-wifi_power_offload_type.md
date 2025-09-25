## Description

The **WIFI_POWER_OFFLOAD_TYPE** enumeration specifies the type for a low power offload protocol offload to a WiFiCx network adapter.

## Constants

### `WifiPowerOffloadType80211RsnRekey:1`

The power offload is the 802.11 RSN rekey protocol.

### `WifiPowerOffloadTypeWakeOnIncomingActionFrame:2`

The power offload is for waking on incoming action frame reception.

## Remarks

Call [**WifiPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgettype) to get the type for a low power protocol offload to a WiFiCx network adapter.

## See also

[**WifiPowerOffloadGetType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadgettype)