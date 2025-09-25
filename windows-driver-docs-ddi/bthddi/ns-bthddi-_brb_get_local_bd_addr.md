# _BRB_GET_LOCAL_BD_ADDR structure

## Description

The _BRB_GET_LOCAL_BD_ADDR structure describes the address of the local radio.

## Members

### `Hdr`

A
[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header) structure that contains information
about the current BRB.

### `BtAddress`

An output member that receives the address of the local radio.

## Remarks

To get the address of the local radio, profile drivers should
[build and send](https://learn.microsoft.com/previous-versions/ff536657(v=vs.85)) a
[BRB_HCI_GET_LOCAL_BD_ADDR](https://learn.microsoft.com/previous-versions/ff536611(v=vs.85)) request.

Only a single local radio is supported by the Bluetooth driver stack.

## See also

[BRB_HCI_GET_LOCAL_BD_ADDR](https://learn.microsoft.com/previous-versions/ff536611(v=vs.85))

[BRB_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthddi/ns-bthddi-_brb_header)