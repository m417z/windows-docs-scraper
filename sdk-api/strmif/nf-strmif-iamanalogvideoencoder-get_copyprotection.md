# IAMAnalogVideoEncoder::get_CopyProtection

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMAnalogVideoEncoder** interface is deprecated.

The `get_CopyProtection` method determines whether copy protection is currently enabled on the encoder.

## Parameters

### `lVideoCopyProtection` [out]

Specifies a pointer to a **long** integer to receive the current copy protection level, as defined in the [AM_COPY_MACROVISION_LEVEL](https://learn.microsoft.com/previous-versions/ms778997(v=vs.85)) enumeration.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT**

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAnalogVideoEncoder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamanalogvideoencoder)