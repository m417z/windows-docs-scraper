## Description

Structure for supplying bytes or text input to Dxc APIs.

## Members

### `Ptr`

A pointer to the start of the buffer.

### `Size`

The size of the buffer, in bytes.

### `Encoding`

The encoding of the buffer. Use Encoding == 0 for non-text bytes, ANSI text, or unknown with byte-order mark (BOM).

## Remarks

## See also