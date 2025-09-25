# IMF2DBuffer2::Copy2DTo

## Description

Copies the buffer to another 2D buffer object.

## Parameters

### `pDestBuffer` [in]

A pointer to the [IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2) interface of the destination buffer.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The destination buffer must be at least as large as the source buffer.

## See also

[IMF2DBuffer2](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imf2dbuffer2)