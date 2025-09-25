# IConfigAviMux::GetOutputCompatibilityIndex

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetOutputCompatibilityIndex` method retrieves the setting for the AVI index format.

## Parameters

### `pfOldIndex` [out]

Receives one of the following values.

| Value | Description |
| --- | --- |
| **TRUE** | Create an AVI 1.0 index, as well as an AVI 2.0 index. |
| **FALSE** | Create an AVI 2.0 index, but not an AVI 1.0 index. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

The AVI Mux filter always creates an AVI 2.0 index ('indx' format). If the value returned in *pfOldIndex* is **TRUE**, the AVI Mux also creates an AVI 1.0 index ('idx1' format), for backward compatibility with Video for Windows.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAviMux Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iconfigavimux)

[IConfigAviMux::SetOutputCompatibilityIndex](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iconfigavimux-setoutputcompatibilityindex)