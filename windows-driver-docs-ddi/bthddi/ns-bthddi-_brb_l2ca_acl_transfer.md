# _BRB_L2CA_ACL_TRANSFER structure

## Description

The _BRB_L2CA_ACL_TRANSFER structure describes a buffer to read asynchronous data from, or write
asynchronous data to a L2CAP channel.

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
[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85)) request.

### `TransferFlags`

A combination of flags that specifies the basic behavior of the interface. Multiple flags can be
set at the same time. Valid flag values are described in the following table:

| Flag | Description |
| --- | --- |
| ACL_SHORT_TRANSFER_OK | If this bit is set, the read operation can complete before the buffer is full. This can only be set in combination with ACL_TRANSFER_DIRECTION_IN. |
| ACL_TRANSFER_DIRECTION_IN | If this bit is set, data will be received from the remote device. This flag cannot be set in combination with ACL_TRANSFER_DIRECTION_OUT. |
| ACL_TRANSFER_DIRECTION_OUT | If this bit is set, data is to be sent to the remote device. This flag cannot be set in combination with ACL_TRANSFER_DIRECTION_IN. |
| ACL_TRANSFER_TIMEOUT | The read operation should be stopped after the number of milliseconds specified in the **Timeout** member. |

### `BufferSize`

The size, in bytes, of the buffer.

### `Buffer`

A pointer to the input buffer.

### `BufferMDL`

A pointer to the MDL input buffer.

### `Timeout`

The duration, in milliseconds, before the read action is canceled and any data consumed to this
point is lost.

### `RemainingBufferSize`

The amount of space, in bytes, left in the buffer after the BRB call.

## Remarks

To read asynchronous data from, or write asynchronous data to a L2CAP channel, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_ACL_TRANSFER](https://learn.microsoft.com/previous-versions/ff536613(v=vs.85)) request.

Each L2CAP connection is bidirectional, and can be read from and written to simultaneously.

If no timeout is specified, BRBs associated with a read request will remain pending until data arrives
or until they are canceled. Profile drivers can leave a read request pending in order to accept incoming
data from the remote device.

The Bluetooth driver stack provides some buffering of incoming data, so it is not necessary to
continuously check whether a read IRP is pending. A profile driver can specify the amount of buffering to
provide in the
**IncomingQueueDepth** member associated with a
[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85)) request.

If the ACL_TRANSFER_TIMEOUT flag is set in the
**TransferFlags** member and the duration specified in the
**Timeout** member expires, the **BRB_L2CA_ACL_TRANSFER** request will complete and return an error.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_ACL_TRANSFER](https://learn.microsoft.com/previous-versions/ff536613(v=vs.85))

[BRB_L2CA_OPEN_CHANNEL](https://learn.microsoft.com/previous-versions/ff536615(v=vs.85))

[BRB_L2CA_OPEN_CHANNEL_RESPONSE](https://learn.microsoft.com/previous-versions/ff536616(v=vs.85))