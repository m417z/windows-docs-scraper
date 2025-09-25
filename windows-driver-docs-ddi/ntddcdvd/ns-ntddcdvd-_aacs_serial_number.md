# _AACS_SERIAL_NUMBER structure

## Description

The AACS_SERIAL_NUMBER structure contains an Advanced Access Content System (AACS) serial number and corresponding message authentication code (MAC).

## Members

### `PrerecordedSerialNumber`

The serial number.

### `MAC`

The message authentication code (MAC) that the client uses to verify that the serial number is for the current AACS authentication sequence.

## Remarks

Clients retrieve the AACS serial number with an [IOCTL_AACS_READ_SERIAL_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_serial_number) request.

## See also

[IOCTL_AACS_READ_SERIAL_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdvd/ni-ntddcdvd-ioctl_aacs_read_serial_number)