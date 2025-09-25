# _SMARTCARD_REQUEST structure

## Description

Describes the request buffer that contains data to send to the card.

## Members

### `Buffer`

Pointer to a buffer that contains data to send.

### `BufferSize`

Size of the buffer pointed to by *Buffer*.

### `BufferLength`

Number of bytes required for this command.

## See also

[SmcCxGetSmartcardRequestBuffer](https://learn.microsoft.com/previous-versions/dn946593(v=vs.85))