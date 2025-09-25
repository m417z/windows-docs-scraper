# IFullScreenVideoEx::IsModeAvailable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsModeAvailable` method queries whether a specified display mode is available.

## Parameters

### `Mode` [in]

Index of the display mode.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **S_FALSE** | The display mode is not available. |
| **S_OK** | The display mode is available. |

## Remarks

The Full Screen Renderer supports a static set of display modes. However, the video card on the user's system might not support every mode. If a particular display mode is not supported by the video card, this method returns S_FALSE. Even if a particular mode is available, it will not necessarily be used for video playback. The mode must also be compatible with the filters in the filter graph.

You can disable a display mode by calling the [IFullScreenVideoEx::SetEnabled](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-setenabled) method. The Full Screen Renderer will not use a disabled mode, even if the video card supports it.

Display modes are indexed from zero. The [IFullScreenVideoEx::CountModes](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-countmodes) method returns the number of modes.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)