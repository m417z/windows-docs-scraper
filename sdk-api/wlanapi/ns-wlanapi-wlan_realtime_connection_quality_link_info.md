## Description

Contains information about a connected link.

## Members

### `ucLinkID`

The Link ID of the specific link.

### `ulChannelCenterFrequencyMhz`

The channel center frequency of the band on which the 802.11 Beacon or Probe Response frame was received. The value of *ulChannelCenterFrequencyMhz* is in units of kilohertz (kHz).

> [!NOTE]
> This member is valid only for PHY types that are not frequency-hopping spread spectrum (FHSS).

### `ulBandwidth`

Bandwidth of the specific link.

### `lRssi`

The received signal strength indicator (RSSI) value, in units of decibels referenced to 1.0 milliwatts (dBm), as detected by the wireless LAN interface driver for the AP or peer station.

### `wlanRateSet`

A set of data transfer rates supported by the BSS. The data type for this member is a [WLAN_RATE_SET](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_rate_set) structure.

## Remarks

## See also