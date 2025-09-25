# IFullScreenVideoEx::IsModeEnabled

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsModeEnabled` method queries whether a specified display mode is enabled.

## Parameters

### `Mode` [in]

Index of the display mode to query.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **S_FALSE** | The display mode is disabled. |
| **S_OK** | The display mode is enabled. |

## Remarks

The Full Screen Renderer supports a static set of display modes. By default, every mode is enabled. You can enable or disable a display mode by calling the [IFullScreenVideoEx::SetEnabled](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-setenabled). The **IsEnabled** method retrieves the current setting for the specified mode.

The video card on the user's system might not support every mode. The Full Screen Renderer will not use a mode that the video card does not support, even if that mode is enabled. To determine whether the card supports a particular mode, call the [IFullScreenVideoEx::IsModeAvailable](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-ismodeavailable) method. If a mode is disabled, the Full Screen Renderer will not use it, even if the card supports it.

Display modes are indexed from zero. The [IFullScreenVideoEx::CountModes](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-countmodes) method returns the number of modes.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)