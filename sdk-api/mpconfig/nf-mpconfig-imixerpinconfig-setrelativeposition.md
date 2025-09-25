# IMixerPinConfig::SetRelativePosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRelativePosition` method sets the position of the stream in the display window.

## Parameters

### `dwLeft` [in]

Value specifying the x-coordinate in the upper-left corner of the display window.

### `dwTop` [in]

Value specifying the y-coordinate in the upper-left corner of the display window.

### `dwRight` [in]

Value specifying the x-coordinate in the bottom-right corner of the display window.

### `dwBottom` [in]

Value specifying the y-coordinate in the bottom-right corner of the display window.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Coordinates not in the {0, 0, 10,000, 10,000} range. |
| **S_OK** | Success. |

## Remarks

This method assumes window coordinates of {0, 0, 10,000, 10,000}. Therefore, if you want your video stream to be rendered in the bottom right quarter of the display window, you would call this method with the parameters {5,000, 5,000, 10,000, 10,000}.

**Note** Values greater than 10,000 are invalid and will cause an error.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::GetRelativePosition](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getrelativeposition)