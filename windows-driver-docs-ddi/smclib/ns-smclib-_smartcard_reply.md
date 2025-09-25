# _SMARTCARD_REPLY structure

## Description

Describes the reply buffer received from the smart card.

## Members

### `Buffer`

Pointer to a buffer that receives smart card data.

### `BufferSize`

Size of the buffer pointed to by *Buffer*.

### `BufferLength`

Number of bytes received from the card.

## Remarks

The client driver must receive data in this buffer and adjust *BufferLength* to the number of received bytes.

## See also

[SmcCxGetSmartcardReplyBuffer](https://learn.microsoft.com/previous-versions/dn946592(v=vs.85))