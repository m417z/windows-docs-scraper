# IDMOQualityControl::GetStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetStatus` method determines whether quality control is active.

## Parameters

### `pdwFlags` [out]

Pointer to a variable that receives the quality control status. If quality control is disabled, the value is zero. If quality control is enabled, the value is DMO_QUALITY_STATUS_ENABLED.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer value |
| **S_OK** | Success |

## See also

[IDMOQualityControl Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmoqualitycontrol)