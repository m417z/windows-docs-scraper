# _CHANNEL_CONFIG_PARAMETERS_ENHANCED structure

## Description

The CHANNEL_CONFIG_PARAMETERS_ENHANCED structure describes configuration parameters for inbound and outbound directions of an L2CAP channel.

## Members

### `Flags`

Combination of CFG_XXX flags.

### `Mtu`

MTU for the direction.

### `FlushTO`

Flush timeout for the direction

### `NumExtraOptions`

Number of elements in the ExtraOptions array

### `ExtraOptions`

Array of extra options

### `Flow`

QOS for the direction

### `RetransmissionAndFlow`

Retransmission and flow for the direction

### `Fcs`

Frame check sequence

### `ExtendedFlowSpec`

Extended flow specification for the L2CAP channel. This member is reserved. Do not use.

### `ExtendedWindowSize`

Extended window size. This member is reserved. Do not use.