# _SERIALPERF_STATS structure

## Description

The **SERIALPERF_STATS** structure contains performance statistics for a serial port.

## Members

### `ReceivedCount`

The number of characters received since either the serial port was opened or the last [IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats) request was processed.

### `TransmittedCount`

The number of characters transmitted since either the serial port was opened or the last **IOCTL_SERIAL_CLEAR_STATS** request was processed.

### `FrameErrorCount`

The number of frame errors detected since either the serial port was opened or the last **IOCTL_SERIAL_CLEAR_STATS** request was processed.

### `SerialOverrunErrorCount`

The number of serial overrun errors detected since either the serial port was opened or the last **IOCTL_SERIAL_CLEAR_STATS** request was processed.

### `BufferOverrunErrorCount`

The number of buffer overrun errors detected since either the serial port was opened or the last **IOCTL_SERIAL_CLEAR_STATS** request was processed.

### `ParityErrorCount`

The number of parity errors detected since either the serial port was opened or the last **IOCTL_SERIAL_CLEAR_STATS** request was processed.

## Remarks

This structure is used by the [IOCTL_SERIAL_GET_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_stats) request.

To reset the performance statistics to zero, send an [IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats) request.

## See also

[IOCTL_SERIAL_CLEAR_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_clear_stats)

[IOCTL_SERIAL_GET_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_stats)