# IVMRFilterConfig::GetNumberOfStreams

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNumberOfStreams` method retrieves the number of input streams being mixed.

## Parameters

### `pdwMaxStreams` [out]

Pointer to a double word that receives the number of streams being mixed, which is equal to the number of input pins on the VMR.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **E_POINTER** | *pdwMaxStreams* is invalid |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRFilterConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrfilterconfig)

[IVMRFilterConfig::SetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrfilterconfig-setnumberofstreams)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)