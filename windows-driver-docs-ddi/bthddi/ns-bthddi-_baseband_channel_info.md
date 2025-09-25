# _BASEBAND_CHANNEL_INFO structure

## Description

The BASEBAND_CHANNEL_INFO structure describes output information about the baseband channel that is
used by a SCO link after a BRB_GET_CHANNEL_INFO BRB completes.

## Members

### `Transmission_Interval`

The elapsed time, in slots, between two consecutive SCO instants. This member will return zero for
SCO links.

### `Retransmission_Window`

The length of time, in slots, that an eSCO channel can use to retransmit a request. This member
will return zero for SCO links.

### `AirMode`

The air mode data format used by the baseband channel. Possible values include:

A-LAW LOG

CVSD

MU-LAW LOG

TRANSPARENT DATA

### `Rx_Packet_Length`

The size, in bytes, of the eSCO payload in the receive direction. This member will return zero for
SCO links.

### `Tx_Packet_Length`

The size, in bytes, of the eSCO payload in the transmit direction. This member will return zero
for SCO links.

## Remarks

Profile drivers access the BASEBAND_CHANNEL_INFO structure through the
**BasebandInfo** member of the
[_BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info) structure.

## See also

[_BRB_SCO_GET_CHANNEL_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_sco_get_channel_info)