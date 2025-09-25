# _ADDRESS_FIFO structure

## Description

The ADDRESS_FIFO structure is an entry in a singly-linked list of MDLs used by the REQUEST_ALLOCATE_ADDRESS_RANGE IEEE 1394 bus request.

## Members

### `FifoList`

Specifies the rest of the list. This is a singly linked list.

### `FifoMdl`

Specifies the MDL for the FIFO element described by this entry of the list.

## See also

[NOTIFICATION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_notification_info_w2k)

[REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)