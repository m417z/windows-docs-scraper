# _WWAN_SET_SIGNAL_INDICATION structure

## Description

The WWAN_SET_SIGNAL_INDICATION structure represents the frequency of RSSI interval and RSSI threshold
notifications.

## Members

### `RssiInterval`

The RSSI interval, in seconds.

### `RssiThreshold`

The RSSI threshold, in threshold units.

## Remarks

To minimize power consumption, the MB Service specifies a default interval and a default threshold for
sending notifications that are based on an RSSI value that changes. In some situations, such as during
long periods of user inactivity (in the case of the default interval), or in areas that have a strong
signal (in the case of a default threshold), this value specifies when a longer interval or threshold (as
appropriate) may be used to conserve additional power. However, miniport drivers are not required to
adhere to an increased interval or threshold.

The WWAN_RSSI_DEFAULT value indicates that no suggested interval value is available, and that the
miniport driver should use the default minimum interval or the default threshold (as appropriate). A
value of WWAN_RSSI_DISABLE that the miniport driver will stop reporting the signal state based on the
interval or threshold limit (as appropriate).

The miniport driver can always switch to its device-specific default reporting interval if the request
in this member is outside of device limits.

## See also

[NDIS_WWAN_SET_SIGNAL_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_signal_indication)