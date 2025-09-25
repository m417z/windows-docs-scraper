# IWICPalette::GetColors

## Description

Fills out the supplied color array with the colors from the internal color table. The color array should be sized according to the return results from [GetColorCount](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicpalette-getcolorcount).

## Parameters

### `cCount` [in]

Type: **UINT**

The size of the *pColors* array.

### `pColors` [out]

Type: **WICColor***

Pointer that receives the colors of the palette.

### `pcActualColors` [out]

Type: **UINT***

The actual size needed to obtain the palette colors.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.