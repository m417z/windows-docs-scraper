# _BRB_L2CA_CLOSE_CHANNEL structure

## Description

The _BRB_L2CA_CLOSE_CHANNEL structure describes an open L2CAP channel to close.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote device.

### `ChannelHandle`

The L2CAP channel handle that was returned by Bluetooth driver stack in response to an earlier
[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85)) or
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request. This is the channel handle to close.

## Remarks

To close a L2CAP channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_CLOSE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536614(v=vs.85)) request.

A **BRB_L2CA_CLOSE_CHANNEL** request can be made for a channel that was initiated locally or remotely. If
a profile driver has multiple L2CAP channels to a single remote device, it must close each one
individually.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_CLOSE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536614(v=vs.85))

[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85))

[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85))