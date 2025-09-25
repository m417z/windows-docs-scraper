# IWTSBitmapRenderer::Render

## Description

Called by a dynamic virtual channel plug-in to render bitmaps.

## Parameters

### `imageFormat` [in]

Specifies the format of the data in the *pImageBuffer* buffer. This parameter is ignored and only bitmaps can be rendered.

### `dwWidth` [in]

The width of the bitmap.

### `dwHeight` [in]

The height of the bitmap.

### `cbStride` [in]

The stride width of the bitmap.

### `cbImageBuffer` [in]

The size, in bytes, of the *pImageBuffer* buffer.

### `pImageBuffer` [in]

An array of bytes that contains the data to render.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWTSBitmapRenderer](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderer)