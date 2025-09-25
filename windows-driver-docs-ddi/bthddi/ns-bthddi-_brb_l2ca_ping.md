# _BRB_L2CA_PING structure

## Description

The _BRB_L2CA_PING structure describes a request to ping a remote radio.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the device that the ping is sent to.

### `PingRequestLength`

The length, in bytes, of the data to send in the ping signal.

### `PingRequestData`

The data to send in the ping signal.

### `PingResponseLength`

The length, in bytes, of the data that the remote device responded to the ping signal with.

### `PingResponseData`

The data that the remote device responded to the ping signal with.

## Remarks

To ping a remote radio, by transmitting a L2CA_EchoReq message and receiving a L2CAP_EchoRsp message,
profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_PING](https://learn.microsoft.com/previous-versions/ff536617(v=vs.85)) request.

BRB_L2CA_PING is primarily used for debugging.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_PING](https://learn.microsoft.com/previous-versions/ff536617(v=vs.85))