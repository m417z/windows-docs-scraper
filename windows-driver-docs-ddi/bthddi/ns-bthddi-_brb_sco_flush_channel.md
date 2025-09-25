# _BRB_SCO_FLUSH_CHANNEL structure

## Description

The _BRB_SCO_FLUSH_CHANNEL structure describes a flush operation for a SCO channel.

## Members

### `Hdr`

A [BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device.

### `ChannelHandle`

The handle to the SCO channel to flush.

### `FlushFlags`

Valid flags may be combined using a logical OR operation

#### SCO_FLUSH_DIRECTION_OUT

#### SCO_FLUSH_DIRECTION_IN

## Remarks

To flush a SCO channel, profile drivers should [build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a [BRB_SCO_FLUSH_CHANNEL](https://learn.microsoft.com/previous-versions/ff536623(v=vs.85)) request.

All pending data transfer IRPs will be completed with STATUS_REQUEST_ABORTED. In-progress IRPs will be completed normally, with success or failure,depending on whether the Bluetooth driver stack was able to transfer data to or from the remote device.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_FLUSH_CHANNEL](https://learn.microsoft.com/previous-versions/ff536623(v=vs.85))