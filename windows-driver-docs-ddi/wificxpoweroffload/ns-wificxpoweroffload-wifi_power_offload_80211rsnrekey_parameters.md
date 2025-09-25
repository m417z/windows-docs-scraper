## Description

The **WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS** structure contains parameters for an 802.11 RSN rekey low power protocol offload to a WiFiCx net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `ProtocolOffloadId`

The identifier for this protocol offload.

### `ReplayCounter`

A UINT64 value that specifies the replay counter.

### `KCKLength`

The length of the IEEE 802.11 key confirmation key (KCK).

### `KEKLength`

The length of the IEEE 802.11 key encryption key (KEK).

### `KCK`

A UCHAR array that specifies the KCK.

### `KEK`

A UCHAR array that specifies the KEK.

## Remarks

Call [**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters_init) to initialize this structure and fill in its **Size** field. Then call [**WifiPowerOffloadGet80211RSNRekeyParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadget80211rsnrekeyparameters) to fill in the remaining members of the structure.

## See also

[**WIFI_POWER_OFFLOAD_80211RSNREKEY_PARAMETERS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifi_power_offload_80211rsnrekey_parameters_init)

[**WifiPowerOffloadGet80211RSNRekeyParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificxpoweroffload/nf-wificxpoweroffload-wifipoweroffloadget80211rsnrekeyparameters)