# IWTSBitmapRendererCallback::OnTargetSizeChanged

## Description

Called when the size of the render target has changed. The image passed to [IWTSBitmapRenderer::Render](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsbitmaprenderer-render) must conform to this size.

## Parameters

### `rcNewSize` [in]

A **RECT** structure that contains the new size of the render target.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWTSBitmapRendererCallback](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderercallback)