# _BRB_L2CA_UNREGISTER_SERVER structure

## Description

A profile driver uses the _BRB_L2CA_UNREGISTER_SERVER structure to unregister itself as a server
capable of receiving L2CAP connections from remote Bluetooth devices.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

The address of the remote device.

### `ServerHandle`

The handle of the L2CAP server to unregister, as returned earlier from a previous
[BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85)) request.

### `Psm`

The Protocol/Service Multiplexer (PSM) that was specified in a previous
[BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/previous-versions/ff536618(v=vs.85)) request.

## Remarks

To unregister itself as a L2CAP server, a profile driver should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server) request.

## See also

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)

[BRB_L2CA_UNREGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server)

[_BRB_L2CA_REGISTER_SERVER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_l2ca_register_server)