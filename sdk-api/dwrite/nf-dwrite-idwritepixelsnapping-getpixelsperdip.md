# IDWritePixelSnapping::GetPixelsPerDip

## Description

 Gets the number of physical pixels per DIP.

## Parameters

### `clientDrawingContext`

Type: **void***

The drawing context passed to [IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw).

### `pixelsPerDip` [out]

Type: **FLOAT***

When this method returns, contains the number of physical pixels per DIP.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Because a DIP (device-independent pixel) is 1/96 inch,
the *pixelsPerDip* value is the number of logical pixels per inch divided by 96.

## See also

[IDWritePixelSnapping](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritepixelsnapping)