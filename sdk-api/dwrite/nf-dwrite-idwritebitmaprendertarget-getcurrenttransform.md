# IDWriteBitmapRenderTarget::GetCurrentTransform

## Description

 Gets the transform that maps abstract coordinates to DIPs. By default this is the identity
transform. Note that this is unrelated to the world transform of the underlying device
context.

## Parameters

### `transform` [out]

Type: **[DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

When this method returns, contains a transform matrix.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget)