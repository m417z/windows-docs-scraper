# IDWriteBitmapRenderTarget::SetCurrentTransform

## Description

 Sets the transform that maps abstract coordinate to DIPs (device-independent pixel). This does not affect the world
transform of the underlying device context.

## Parameters

### `transform` [in, optional]

Type: **const [DWRITE_MATRIX](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_matrix)***

 Specifies the new transform. This parameter can be **NULL**, in which
case the identity transform is implied.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteBitmapRenderTarget](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritebitmaprendertarget)