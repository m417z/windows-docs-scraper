# IWICPalette::IsGrayscale

## Description

Retrieves a value that describes whether a palette is grayscale.

## Parameters

### `pfIsGrayscale` [out]

Type: **BOOL***

A pointer to a variable that receives a boolean value that indicates whether the palette is grayscale. **TRUE** indicates that the palette is grayscale; otherwise **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A palette is considered grayscale only if, for every entry, the alpha value is 0xFF and the red, green and blue values match.