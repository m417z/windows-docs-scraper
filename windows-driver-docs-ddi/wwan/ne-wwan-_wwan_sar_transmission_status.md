# _WWAN_SAR_TRANSMISSION_STATUS enumeration

## Description

The **WWAN_SAR_TRANSMISSION_STATUS** enumeration describes whether a mobile broadband (MBB) modem has transmit (Tx) traffic during its hysteresis timer.

## Constants

### `WwanTransmissionStateInactive`

The modem was not actively transmitting data, without any continuous lapse in transmission, for the last hysteresis timer value.

### `WwanTransmissionStateActive`

The modem was actively transmitting data.

## Remarks

This enumeration is used in the [**WWAN_SAR_TRANSMISSION_STATUS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_transmission_status_info) structure.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-transmission-status)

[**WWAN_SAR_TRANSMISSION_STATUS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_transmission_status_info)