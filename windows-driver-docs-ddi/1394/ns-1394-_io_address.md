# _IO_ADDRESS structure

## Description

The IO_ADDRESS structure specifies the 1394 64-bit destination address for read, write and lock operations.

## Members

### `IA_Destination_ID`

Holds a structure of type [NODE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_node_address) containing the destination node address.

### `IA_Destination_Offset`

Holds a structure of type [ADDRESS_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_address_offset) that specifies the index of the 1394 address within the address array.

## See also

[ADDRESS_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_address_offset)

[NODE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_node_address)

[REQUEST_ASYNC_LOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ASYNC_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ASYNC_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_GET_CONFIGURATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)