# IDMOQualityControl::SetStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetStatus` method enables or disables quality control.

## Parameters

### `dwFlags` [in]

Value that specifies whether to enable or disable quality control. Use DMO_QUALITY_STATUS_ENABLED to enable quality control, or zero to disable quality control.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## Remarks

With quality control enabled, the DMO attempts to deliver samples on time. It can skip late samples if necessary. With quality control disabled, the DMO delivers every sample. If you enable quality control, call the [IDMOQualityControl::SetNow](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-idmoqualitycontrol-setnow) method to specify the earliest time stamp that the DMO should process. Otherwise, the call to `SetStatus` succeeds but the DMO does not perform quality control.

By default, quality control is disabled.

## See also

[IDMOQualityControl Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmoqualitycontrol)