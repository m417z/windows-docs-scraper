# IDDrawExclModeVideo::GetNativeVideoProps

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNativeVideoProps` method retrieves the current video size and picture aspect ratio of the Overlay Mixer's primary stream.

## Parameters

### `pdwVideoWidth` [out]

Address of variable that receives the width of the video.

### `pdwVideoHeight` [out]

Address of variable that receives the height of the video.

### `pdwPictAspectRatioX` [out]

Address of variable that receives the x-axis aspect ratio.

### `pdwPictAspectRatioY` [out]

Address of variable that receives the y-axis aspect ratio.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Argument is invalid. |

## Remarks

The filter graph should look for the [EC_VIDEO_SIZE_CHANGED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-video-size-changed) event, and on its receipt call this method to adjust the aspect ratio and position.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideo)