# _L2CAP_CONFIG_RANGE structure

## Description

The L2CAP_CONFIG_RANGE structure is used to specify a range of possible values for the
**FlushTO** member of the
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) structure during
incoming requests.

## Members

### `Min`

The minimum value that the local system can accept.

### `Max`

The maximum value that the local system can accept.

## Remarks

The L2CAP_CONFIG_RANGE structure contains the range of values that the profile driver uses to
negotiate a flush timeout when a remote device contacts the profile driver to request a L2CAP connection.
Profile drivers build and send a **BRB_L2CA_OPEN_CHANNEL_RESPONSE** request to either accept or reject the
settings sent by the requesting device. If the preferred value that is sent by the requesting device
falls in the range specified by this structure's
**Min** and
**Max** members, the
**FlushTO** settings are accepted. If the profile driver rejects the setting as being too long, the
profile driver responds with the value of the
**Max** member, the maximum setting it will accept. If this value falls within the range requested by
the remote device, the
**FlushTO** value is accepted. Otherwise, the profile driver rejects the
**FlushTO** value and the connection attempt fails.

If the profile driver rejects the remote device's preferred timeout value as being too short, the
profile driver responds with the value of the
**Min** member value, the minimum setting it will accept. If the profile driver's minimum flush timeout
falls within the range requested by the remote device, the profile driver accepts the
**FlushTO** value. Otherwise, the profile driver rejects the
**FlushTO** value and the connection attempt fails.

A profile driver negotiates these values separately from the flush timeout settings it requests when
it attempts to open an outbound channel to a remote device using the **BRB_L2CA_OPEN_CHANNEL** request. For
more information about value ranges, see
[L2CAP_CONFIG_VALUE_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_l2cap_config_value_range).

## See also

[L2CAP_CONFIG_VALUE_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_l2cap_config_value_range)

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)