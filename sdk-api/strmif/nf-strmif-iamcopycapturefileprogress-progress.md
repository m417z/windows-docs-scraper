# IAMCopyCaptureFileProgress::Progress

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Progress` method is called periodically by the [ICaptureGraphBuilder2::CopyCaptureFile](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icapturegraphbuilder2-copycapturefile) method while it copies the file.

## Parameters

### `iProgress` [in]

Specifies the percentage of the copy operation that has completed, as a value between 0 and 100.

## Return value

Returns S_OK or an **HRESULT** error code.

## Remarks

Applications typically use the value of *iProgress* to update a progress bar on the user interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMCopyCaptureFileProgress Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamcopycapturefileprogress)