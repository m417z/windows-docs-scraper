# TRANSMIT_FILE_BUFFERS structure

## Description

The
**TRANSMIT_FILE_BUFFERS** structure specifies data to be transmitted before and after file data during a
[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) function file transfer operation.

## Members

### `Head`

Pointer to a buffer that contains data to be transmitted before the file data is transmitted.

### `HeadLength`

Size of the buffer pointed to by **Head**, in bytes, to be transmitted.

### `Tail`

Pointer to a buffer that contains data to be transmitted after the file data is transmitted.

### `TailLength`

Size of the buffer pointed to **Tail**, in bytes, to be transmitted.

## See also

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)