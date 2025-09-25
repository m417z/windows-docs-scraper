# _BINARY_CONTAINER structure

## Description

The BINARY_CONTAINER structure is a container for binary data.

## Members

### `cbBuf`

Specifies the number of bytes of binary data in the **pData** member.

### `pData`

Pointer to a buffer that contains the binary data.

## Remarks

The BINARY_CONTAINER structure is used in a [BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data) structure when the bidi data consists of binary data, as opposed to integer, float, or string data.

## See also

[BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data)