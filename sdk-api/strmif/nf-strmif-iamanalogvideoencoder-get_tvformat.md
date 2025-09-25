# IAMAnalogVideoEncoder::get_TVFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMAnalogVideoEncoder** interface is deprecated.

The `get_TVFormat` method retrieves the analog video standard that the encoder is currently set to (NTSC/M, PAL/B, SECAM/K1, and so on).

## Parameters

### `plAnalogVideoStandard` [out]

Specifies a pointer to a **long** integer to receive the encoder's current video standard.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Possible values and their meaning are defined in the [AnalogVideoStandard](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-analogvideostandard) enumeration.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAnalogVideoEncoder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamanalogvideoencoder)