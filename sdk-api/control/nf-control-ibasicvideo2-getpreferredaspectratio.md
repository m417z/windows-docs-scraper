# IBasicVideo2::GetPreferredAspectRatio

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetPreferredAspectRatio` method retrieves the preferred aspect ratio.

## Parameters

### `plAspectX` [out]

Pointer to a value that indicates the x-axis aspect ratio.

### `plAspectY` [out]

Pointer to a value that indicates the y-axis aspect ratio.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or both of the parameters are invalid. |
| **E_NOINTERFACE** | The renderer does not implement **IBasicVideo2**. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo2 Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo2)