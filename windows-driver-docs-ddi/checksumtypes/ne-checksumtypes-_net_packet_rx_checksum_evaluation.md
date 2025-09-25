# NET_PACKET_RX_CHECKSUM_EVALUATION enumeration

## Description

The **NET_PACKET_RX_CHECKSUM_EVALUATION** enumeration specifies checksum evaluation flags for a [**NET_PACKET_CHECKSUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ns-checksumtypes-_net_packet_checksum) structure during packet reception.

## Constants

### `NetPacketRxChecksumEvaluationNotChecked:0`

The default value for this enumeration. Indicates that the checksum will be validated in software further up in the networking stack.

### `NetPacketRxChecksumEvaluationValid:1`

Indicates the hardware determined that the checksum value is correct.

### `NetPacketRxChecksumEvaluationInvalid:2`

Indicates the hardware determined that the checksum value is incorrect.

## Remarks

## See also

[**NET_PACKET_CHECKSUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ns-checksumtypes-_net_packet_checksum)