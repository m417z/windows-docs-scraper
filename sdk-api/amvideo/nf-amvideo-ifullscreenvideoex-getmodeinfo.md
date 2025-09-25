# IFullScreenVideoEx::GetModeInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetModeInfo` method retrieves information about a specified display mode supported by the Full Screen Renderer filter.

## Parameters

### `Mode` [in]

Index of the display mode.

### `pWidth` [out]

Pointer to a variable that receives the width of the display mode, in pixels.

### `pHeight` [out]

Pointer to a variable that receives the height of the display mode, in pixels.

### `pDepth` [out]

Pointer to a variable that receives the bit depth of the display mode.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Index out of range. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | The specified display mode is not available and is disabled. |
| **S_OK** | Success. |

## Remarks

Display modes are indexed from zero. The [IFullScreenVideoEx::CountModes](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-countmodes) method returns the number of modes.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)