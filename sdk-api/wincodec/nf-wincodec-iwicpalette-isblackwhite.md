# IWICPalette::IsBlackWhite

## Description

Retrieves a value that describes whether the palette is black and white.

## Parameters

### `pfIsBlackWhite` [out]

Type: **BOOL***

A pointer to a variable that receives a boolean value that indicates whether the palette is black and white. **TRUE** indicates that the palette is black and white; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A palette is considered to be black and white only if it contains exactly two entries, one full black (0xFF000000) and one full white (0xFFFFFFF).