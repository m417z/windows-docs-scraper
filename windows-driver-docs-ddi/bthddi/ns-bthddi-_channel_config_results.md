# _CHANNEL_CONFIG_RESULTS structure

## Description

The CHANNEL_CONFIG_RESULTS structure contains configuration parameters and the buffer size of any
extra options for the inbound and outbound directions of a L2CAP channel.

## Members

### `Params`

A
[CHANNEL_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters) structure that contains the parameters for the specified direction of
the channel.

### `ExtraOptionsBufferSize`

The size, in bytes, required in the buffer to retrieve the current extra options for the specified
direction.

## Remarks

The CHANNEL_CONFIG_RESULTS structure is passed in the
**InResults** and
**OutResults** members of the
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) structure.

## See also

[CHANNEL_CONFIG_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_channel_config_parameters)

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)