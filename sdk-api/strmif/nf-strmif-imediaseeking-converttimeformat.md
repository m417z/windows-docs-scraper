# IMediaSeeking::ConvertTimeFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ConvertTimeFormat` method converts from one time format to another.

## Parameters

### `pTarget` [out]

Pointer to a variable that receives the converted time.

### `pTargetFormat` [in]

Pointer to a GUID that specifies the target format. If **NULL**, the current format is used. See [Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids).

### `Source` [in]

Time value to be converted.

### `pSourceFormat` [in]

Pointer to a GUID that specifies the format to convert. If **NULL**, the current format is used. See [Time Format GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/time-format-guids).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Conversion between these types is not supported. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSeeking Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediaseeking)