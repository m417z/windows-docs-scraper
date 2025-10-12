# _WWAN_SIGNAL_STATE structure

## Description

The WWAN_SIGNAL_STATE structure represents the signal state of the MB device.

## Members

### `Rssi`

A value that represents the strength of the wireless signal. Miniport drivers that report their
WWAN_CELLULAR_CLASS to be
**WwanCellularClassGSM** or
**WwanCellularClassCDMA** must report Rssi in decibels above the device's sensitivity noise floor.

| Signal Strength (in dBm) | Coded Value (Minimum=0, Maximum=31) |
| --- | --- |
| -113 or less | 0 |
| -111 | 1 |
| -109 | 2 |
| ... | ... |
| -51 or greater | 31 |
| Unknown or undetectable | WWAN_RSSI_UNKNOWN |

CDMA-based devices must report signal strength based on compensated RSSI (accounts for noise) and not
based on raw RSSI.

### `ErrorRate`

A coded value that represents a percentage range of error rates. For GSM-based devices, use the
values from the Channel bit error rate column in the following table. For CDMA-based devices, use the
values from the Frame error rate column. For both cases, use WWAN_ERROR_RATE_UNKNOWN to denote an
unknown error rate.

| Channel bit error rate (in %) | Frame error rate (in %) | Coded value (Min=0, Max=7) |
| --- | --- | --- |
| < 0.2 | < 0.01 | 0 |
| 0.2-0.4 | 0.01-0.1 | 1 |
| 0.4-0.8 | 0.1-0.5 | 2 |
| 0.8-1.6 | 0.5-1.0 | 3 |
| - 3.2 | 1.0 - -2.0 | 4 |
| - 6.4 | 2.0-4.0 | 5 |
| 6.4-12.8 | 4.0-8.0 | 6 |
| > 12.8 | > 8.0 | 7 |
| Unknown or undetectable | | WWAN_ERROR_RATE_UNKNOWN |

### `RssiInterval`

The current interval, in seconds, at which the miniport driver has been set to (or the default
interval, if one has not been set), that the miniport driver will provide updates about the signal
state. Specify WWAN_RSSI_DISABLE to indicate that the miniport driver does not implement interval-based
reporting. Miniport drivers should populate this member with the interval in response to an earlier
request from the MB Service for WWAN_RSSI_DEFAULT.

### `RssiThreshold`

The current threshold, in threshold units, at which the miniport driver has been set to (or the
default interval, if one has not been set), that the miniport driver will provide updates about the
signal state. Specify WWAN_RSSI_DISABLE to indicate that the miniport driver does not implement
threshold-based reporting. Miniport drivers should populate this member with the threshold units in
response to an earlier request from the MB Service for WWAN_RSSI_DEFAULT.

### `SignalStateListHeader`

A formatted [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) structure that represents a list of signal state extensions per data class and the number of data classes. The miniport driver must return a list of all supported data classes.

This member points to a list of [**WWAN_SIGNAL_STATE_EXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state_ext) structures that use the **WWAN_LIST_HEADER** structure. The rest of the members of the **WWAN_SIGNAL_STATE_EXT** structures are filled based on the highest available data class.

## See also

[NDIS_WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_signal_state)