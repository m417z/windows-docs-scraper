## Description

The **KS_MPEGAUDIOINFO** structure describes an MPEG audio stream.

## Members

### `dwFlags`

Specifies the time base for audio timestamps. Reject the connection if undefined bits are not 0. The following flag is defined.

| Flag | Meaning |
|---|---|
| KS_MPEGAUDIOINFO_27MhzTimebase | Specifies that PTS and DTS timestamps advance at 27 MHz rather than 90 kHz. |

### `dwReserved1`

Must be 0; otherwise, reject the connection.

### `dwReserved2`

Must be 0; otherwise, reject the connection.

### `dwReserved3`

Must be 0; otherwise, reject the connection.