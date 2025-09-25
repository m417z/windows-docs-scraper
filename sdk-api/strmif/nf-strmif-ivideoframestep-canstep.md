# IVideoFrameStep::CanStep

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CanStep` method determines the stepping capabilities of the specified filter.

## Parameters

### `bMultiple`

If *bMultiple* is zero and the method returns S_OK, the graph can step one frame at a time. If *bMultiple* if greater than zero and the method returns S_OK, the graph can step *bMultiple* frames at a time.

### `pStepObject`

Pointer to an interface on the filter that will control the stepping operation. Specify **NULL** to perform frame stepping using the renderer filter in the graph. If the graph includes a custom filter that implements the frame stepping, then *pStepObject* should specify that filter's [IBaseFilter](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ibasefilter) interface.

## Return value

Returns S_OK if the object can step or E_INVALIDARG if *pStepObject* is invalid.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVideoFrameStep Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivideoframestep)