# IDMOQualityControl::SetNow

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetNow` method specifies the earliest time stamp that the DMO will deliver.

## Parameters

### `rtNow` [in]

Reference time specifying the earliest time stamp to deliver.

## Return value

Returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **S_OK** | Success |

## Remarks

If quality control is enabled, the DMO discards any samples whose time stamp is less than *rtNow*. Samples whose time stamp is *rtNow* or later are processed as efficiently as possible. Depending on the implementation, the DMO might drop some samples to keep pace.

If quality control is disabled, this method has no immediate effect. However, the DMO stores the specified reference time. It uses this value if quality control is enabled at a later time. To enable quality control, call the [IDMOQualityControl::SetStatus](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-idmoqualitycontrol-setstatus) method.

If incoming samples are not time-stamped, the DMO never performs quality control. The application sets the time stamp in the [IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput) method.

## See also

[IDMOQualityControl Interface](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-idmoqualitycontrol)