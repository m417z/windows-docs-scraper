# _ADDRESS_RANGE structure

## Description

The ADDRESS_RANGE structure describes a range in a IEEE 1394 device's address space.

## Members

### `AR_Off_High`

Specifies the high order bits of the 1394 address within the buffer.

### `AR_Length`

Specifies the length, in bytes, of a 1394 address buffer.

### `AR_Off_Low`

Specifies the low order bits of the 1394 address within the buffer.

## See also

[REQUEST_ALLOCATE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_FREE_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)