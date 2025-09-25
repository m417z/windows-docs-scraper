# _BRB_SCO_TRANSFER structure

## Description

The _BRB_SCO_TRANSFER structure describes a buffer to read isochronous data from, or write isochronous data to a SCO channel.

## Members

### `Hdr`

A [BRB\_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information about the current BRB.

### `BtAddress`

The Bluetooth address of the remote device.

### `ChannelHandle`

The SCO channel handle that was returned by Bluetooth driver stack in response to an earlier [BRB\_SCO\_OPEN\_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85)) or [BRB\_SCO\_OPEN\_CHANNEL\_RESPONSE](https://learn.microsoft.com/previous-versions/ff536627(v%3dvs.85)) request.

### `TransferFlags`

Flags that specify the basic behavior of the BRB. Valid flag values are listed in the following table.

| Flag | Description |
| ---- | ----------- |
| SCO_TRANSFER_DIRECTION_IN | If this bit is set, the BRB reads isochronous data from a remote device through the SCO channel. |
| SCO_TRANSFER_DIRECTION_OUT | If this bit is set, the BRB writes isochronous data to a remote device through the SCO channel. |

### `BufferSize`

The size, in bytes, of the input buffer described by the **Buffer** member of this structure.

### `Buffer`

A pointer to the input buffer. This value should be **NULL** when the **Buffer** member is not used.

### `BufferMDL`

A pointer to the MDL input buffer. This value should be **NULL** when the **BufferMDL** member is not used.

### `DataTag`

SCO write

## Remarks

To read isochronous data from or write isochronous data to a SCO connection, profile drivers should [build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a [BRB\_SCO\_TRANSFER](https://learn.microsoft.com/previous-versions/ff536629(v=vs.85)) request.

Each SCO connection is bidirectional, and can be read from and written to simultaneously.

Read BRBs will remain pending until data arrives or until the profile driver flushes them. It is recommended that higher-level drivers have at least two pending read BRBs open at any time to accept incoming data from the remote device.

The Bluetooth driver stack does not provide any buffering for incoming isochronous data. Therefore a small gap between the completion of one read IRP and the submission of the next can cause data loss.

If both **Buffer** and **BufferMDL** contain non-**NULL** values, then **BufferMDL** takes precedence.

## See also

[BRB\_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB\_SCO\_OPEN\_CHANNEL](https://learn.microsoft.com/previous-versions/ff536626(v=vs.85))

[BRB\_SCO\_OPEN\_CHANNEL\_RESPONSE](https://learn.microsoft.com/previous-versions/ff536627(v%3dvs.85))

[BRB\_SCO\_TRANSFER](https://learn.microsoft.com/previous-versions/ff536629(v=vs.85))