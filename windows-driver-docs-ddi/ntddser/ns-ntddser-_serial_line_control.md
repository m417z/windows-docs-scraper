# _SERIAL_LINE_CONTROL structure

## Description

The **SERIAL_LINE_CONTROL** structure describes the control settings for the serial line.

## Members

### `StopBits`

The number of stop bits used at the end of each character that is transmitted or received. This member is set to one of the following values.

| Value | Description |
| --- | --- |
| STOP_BIT_1 | One stop bit. |
| STOP_BITS_1_5 | One and a half stop bits. |
| STOP_BITS_2 | Two stop bits. Not valid if **WordLength** = 5. |

### `Parity`

The type of parity checking used for each character that is transmitted or received. This member is set to one of the following values.

| Value | Description |
| --- | --- |
| NO_PARITY | No parity bit is used. |
| ODD_PARITY | Odd parity is used. The parity bit is 0 if the number of 1s in the character value is odd. Otherwise, the parity bit is 1. |
| EVEN_PARITY | Even parity is used. The parity bit is 0 if the number of 1s in the character value is even. Otherwise, the parity bit is 1. |
| MARK_PARITY | The parity bit is always set to 1. |
| SPACE_PARITY | The parity bit is always set to 0. |

### `WordLength`

Data bits per character. This member indicates the number of data bits in each character value that is transmitted or received, and does not include parity bits or stop bits. **WordLength** values in the range 5 to 8 are typically supported.

## Remarks

This structure is used by the [IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control) and [IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control) requests.

## See also

[IOCTL_SERIAL_GET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_get_line_control)

[IOCTL_SERIAL_SET_LINE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_line_control)