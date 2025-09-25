# IMediaControl::RenderFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenderFile` method builds a filter graph that renders the specified file.

This method is intended for use by Visual Basic 6.0 applications. It was documented for Visual Basic 6.0 as the **FilgraphManager.RenderFile** method. C++ applications should use the [IGraphBuilder::RenderFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphbuilder-renderfile) method instead.

## Parameters

### `strFilename` [in]

Specifies the name of the file to load.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMediaControl Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol)