# _BRB_SCO_CLOSE_CHANNEL structure

## Description

The _BRB_SCO_CLOSE_CHANNEL structure describes a currently open SCO channel to close.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device.

### `ChannelHandle`

The handle to the SCO channel to close.

## Remarks

To close a SCO channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_CLOSE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536622(v=vs.85)) request.

A **BRB_SCO_CLOSE_CHANNEL** request can be made for a channel that was initiated locally or remotely. If a
profile driver has multiple SCO connections to a single remote device, it must close each one
individually.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_CLOSE_CHANNEL](https://learn.microsoft.com/previous-versions/ff536622(v=vs.85))