# IDWritePixelSnapping::GetCurrentTransform

## Description

 Gets a transform that maps abstract coordinates to DIPs.

## Parameters

### `clientDrawingContext`

Type: **void***

The drawing context passed to [IDWriteTextLayout::Draw](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritetextlayout-draw).

### `transform` [out]

Type: **[DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

When this method returns, contains a structure which has transform information for pixel snapping.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWritePixelSnapping](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritepixelsnapping)