# IIPDVDec::get_IPDisplay

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_IPDisplay` method gets the decoding resolution.

## Parameters

### `displayPix`

Receives a member of the [DVDECODERRESOLUTION](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-_dvresolution) enumerated type, specifying the decoding resolution.

## Return value

Returns S_OK.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IIPDVDec Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iipdvdec)