# IFileSinkFilter::SetFileName

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetFileName` method sets the name of the file into which media samples will be written.

## Parameters

### `pszFileName` [in]

Pointer to the name of the file to receive the media samples.

### `pmt` [in]

Pointer to the type of media samples to be written to the file, and the media type of the sink filter's input pin.

## Return value

Returns an **HRESULT** value.

## Remarks

If the *pszFileName* parameter names a nonexistent file, the file will be created. If it names an existing file, the sink filter will overwrite the file without first deleting it.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFileSinkFilter Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesinkfilter)

[IFileSinkFilter2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifilesinkfilter2)