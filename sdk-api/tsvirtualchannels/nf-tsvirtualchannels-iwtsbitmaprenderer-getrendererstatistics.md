# IWTSBitmapRenderer::GetRendererStatistics

## Description

Retrieves statistics for the RemoteFX media redirection bitmap renderer.

## Parameters

### `pStatistics` [out]

Type: **[BITMAP_RENDERER_STATISTICS](https://learn.microsoft.com/windows/win32/api/tsvirtualchannels/ns-tsvirtualchannels-bitmap_renderer_statistics)***

The address of a
[BITMAP_RENDERER_STATISTICS](https://learn.microsoft.com/windows/win32/api/tsvirtualchannels/ns-tsvirtualchannels-bitmap_renderer_statistics) structure
that receives the bitmap rendering statistics.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[BITMAP_RENDERER_STATISTICS](https://learn.microsoft.com/windows/win32/api/tsvirtualchannels/ns-tsvirtualchannels-bitmap_renderer_statistics)

[IWTSBitmapRenderer](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nn-tsvirtualchannels-iwtsbitmaprenderer)