# _SCO_RETRANSMISSION_EFFORT enumeration

## Description

The SCO_RETRANSMISSION_EFFORT enumeration type is used to determine the retransmission policies of a
SCO channel.

## Constants

### `SCO_RETRANSMISSION_NONE`

The profile driver specifies that there should be no retransmissions on the channel.

### `SCO_RETRANSMISSION_MIN1_POWER`

The profile driver specifies that there should be at least one retransmission on the channel. Any
retransmissions that are performed should be optimized for power consumption.

### `SCO_RETRANSMISSION_MIN1_QUALITY`

The profile driver specifies that there should be at least one retransmission on the channel. Any
retransmissions that are performed should be optimized for link quality.

### `SCO_RETRANSMISSION_DONT_CARE`

The profile driver specifies that retransmissions can occur, but are not required.