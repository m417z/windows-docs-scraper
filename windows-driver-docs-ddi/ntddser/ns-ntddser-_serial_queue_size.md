# _SERIAL_QUEUE_SIZE structure

## Description

The **SERIAL_QUEUE_SIZE** structure is used to resize the input buffer that the serial controller driver uses for serial receive operations.

## Members

### `InSize`

Number of bytes requested for the input buffer. For more information, see Remarks.

### `OutSize`

Not used. Set to zero.

## Remarks

This structure is used by [IOCTL_SERIAL_SET_QUEUE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_queue_size) requests to specify the size requested for the new input buffer. This buffer is used internally by the serial controller driver to hold data received from the serial controller until the data can be copied to an [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) request packet. If the requested buffer size is greater than the current receive buffer size, a new receive buffer is created. Otherwise, the receive buffer is not changed.

## See also

[IOCTL_SERIAL_SET_QUEUE_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_queue_size)

[IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)