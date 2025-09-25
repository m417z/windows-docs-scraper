# _NODE_ADDRESS structure

## Description

The NODE_ADDRESS structure specifies the 10-bit bus number and 6-bit node number that serve as the node address for a 1394 node.

## Members

### `NA_Node_Number`

Specifies the 6-bit node number. This member contains bits 10-15 of the node address.

### `NA_Bus_Number`

Specifies the 10-bit bus number. This member specifies bits 0-10 of the node address.

## See also

[BUS_GENERATION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_bus_generation_node)

[IO_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_io_address)