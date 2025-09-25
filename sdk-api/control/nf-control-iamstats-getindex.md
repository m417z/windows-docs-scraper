# IAMStats::GetIndex

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetIndex` method retrieves the index for a named statistic, or creates a new statistic.

## Parameters

### `szName` [in]

Specifies the name of the statistic.

### `lCreate` [in]

Specifies whether to create the statistic, if it is not defined already. If the value is **TRUE**, the method creates a new index for the statistic when it cannot find an existing entry with that name. If the value is **FALSE**, the method fails when the statistic does not already exist.

### `plIndex` [out]

Receives the index.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | No match for this name. |
| **E_POINTER** | **NULL** pointer argument. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStats Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-iamstats)