# NET_PACKET_TX_CHECKSUM_ACTION enumeration

## Description

The **NET_PACKET_TX_CHECKSUM_ACTION** enumeration specifies checksum action flags for a [**NET_PACKET_CHECKSUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ns-checksumtypes-_net_packet_checksum) structure during packet transmission.

## Constants

### `NetPacketTxChecksumActionPassthrough:0`

Indicates the client should not perform checksum calculation for this layer.

### `NetPacketTxChecksumActionRequired:2`

Indicates the client should perform checksum calculation for this layer.

## Remarks

## See also

[**NET_PACKET_CHECKSUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ns-checksumtypes-_net_packet_checksum)