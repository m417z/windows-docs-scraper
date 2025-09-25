# _SERIAL_BAUD_RATE structure

## Description

The **SERIAL_BAUD_RATE** structure specifies the baud rate at which a serial port is currently configured to transmit and receive data.

## Members

### `BaudRate`

The baud rate. This parameter specifies the number of bits per second that a serial port is currently configured to transmit or receive. For example, a **BaudRate** value of 115200 indicates that the port is configured to transfer 115,200 bits per second.

## Remarks

The [IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate) and [IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate) I/O control requests use the **SERIAL_BAUD_RATE** structure to specify the baud rate of a serial port. The **IOCTL_SERIAL_SET_BAUD_RATE** request configures a serial port to operate at a specified baud rate. The **IOCTL_SERIAL_GET_BAUD_RATE** request queries a serial port for the baud rate that it is currently configured to operate at.

For more information about some of the possible baud rates that a serial controller driver might support, see the description of the **MaxBaud** member in [SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop).

## See also

[IOCTL_SERIAL_GET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_baud_rate)

[IOCTL_SERIAL_SET_BAUD_RATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_baud_rate)

[SERIAL_COMMPROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_commprop)