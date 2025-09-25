# _BRB_SCO_UNREGISTER_SERVER structure

## Description

A profile driver uses the _BRB_SCO_UNREGISTER_SERVER structure to unregister itself as a server
capable of receiving SCO connections from remote Bluetooth devices.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote device.

### `ServerHandle`

The handle of the SCO server to unregister, that was obtained earlier from
BRB_SCO_REGISTER_SERVER.

## Remarks

To unregister itself as a SCO server, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85)) request.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_SCO_UNREGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536630(v=vs.85))