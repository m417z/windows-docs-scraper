# IDecimateVideoImage::SetDecimationImageSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDecimationImageSize` method specifies the dimensions to which the decoder should decimate its output image.

## Parameters

### `lWidth` [in]

Specifies the width of the video image, in pixels.

### `lHeight` [in]

Specifies the height of the video image, in pixels.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The decoder cannot perform any decimation, or needs to halt decimation it is currently performing. |
| **S_OK** | The decoder can decimate the video to the requested size. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDecimateVideoImage Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idecimatevideoimage)