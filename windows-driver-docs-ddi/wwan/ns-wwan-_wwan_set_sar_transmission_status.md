# _WWAN_SET_SAR_TRANSMISSION_STATUS structure

## Description

The **WWAN_SET_SAR_TRANSMISSION_STATUS** structure sets Specific Absorption Rate (SAR) transmission status in a mobile broadband (MBB) modem.

## Members

### `ChannelNotification`

A [**WWAN_SAR_TRANSMISSION_STATUS_NOTIFICATION_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_transmission_status_notification_state) value that specifies whether notifications for SAR transmission are disabled or enabled.

### `HysteresisTimer`

A Hysteresis indicator that is used by the modem to determine when to send a [NDIS_STATUS_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sar-transmission-status) notification to the host. This value is the timer the modem sees as a continuous no-transmit activity before it sends an OFF indicator to host. This timer should be set in seconds, ranging from 1 second to 5 seconds.

## Remarks

This structure is used in the [**NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_sar_transmission_status) structure.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-transmission-status)

[NDIS_STATUS_WWAN_SAR_TRANSMISSION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sar-transmission-status)

[**NDIS_WWAN_SET_SAR_TRANSMISSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_sar_transmission_status)