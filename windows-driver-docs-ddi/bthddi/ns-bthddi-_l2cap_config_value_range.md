# _L2CAP_CONFIG_VALUE_RANGE structure

## Description

The L2CAP_CONFIG_VALUE_RANGE structure is used to specify values for the
**Mtu** and
**FlushTO** members of the
[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel) structure.

## Members

### `Min`

The minimum value that the local system will accept.

### `Preferred`

The ideal value that the local system requests that the remote device accept.

### `Max`

The maximum value that the local system will accept.

## Remarks

For
**FlushTO** member settings, the L2CAP_CONFIG_VALUE_RANGE structure contains the profile driver's ideal
flush timeout value in the
**Preferred** member, along with a range of acceptable values as specified by the
**Min** and
**Max** members.

The profile driver uses a **BRB_L2CA_OPEN_CHANNEL** request to send these settings to a remote device with
which it is attempting to create a L2CAP connection. If the
**Preferred** value that is sent by the profile driver falls in the range specified by the remote
device, the
**FlushTO** settings are accepted. If the remote device rejects the setting as being too long, the
remote device responds with the maximum setting it will accept. If the remote device's maximum flush
timeout falls within the range defined by the
**Min** and
**Max** members, the
**FlushTO** value is accepted. Otherwise, the remote device rejects the
**FlushTO** value and the connection attempt fails.

If the remote device rejects the profile driver's
**Preferred** member value as being too short, the remote device responds with the minimum settings it
will accept. If the remote device's minimum flush timeout falls within the range defined by the
**Min** and
**Max** members, the
**FlushTO** value is accepted. Otherwise, the remote device rejects the
**FlushTO** value and the connection attempt fails.

The profile driver negotiates these values separately from the flush timeout settings that it sends to
the Bluetooth driver stack when a remote device attempts to create an inbound L2CAP channel to the
profile driver. For more information about L2CAP configuration ranges, see
[L2CAP_CONFIG_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_l2cap_config_range).

For
**Mtu** members settings, this structure provides
**Preferred**,
**Min**, and
**Max** settings for both inbound and outbound connections.

## See also

[_BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_open_channel)