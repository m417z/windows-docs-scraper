# IAMVideoProcAmp::GetRange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetRange` method gets the range and default value of a specified video property.

## Parameters

### `Property` [in]

Specifies the property to query, as a value from the [VideoProcAmpProperty](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampproperty) enumeration.

### `pMin` [out]

Receives the minimum value of the property.

### `pMax` [out]

Receives the maximum value of the property.

### `pSteppingDelta` [out]

Receives the step size for the property. The step size is the smallest increment by which the property can change.

### `pDefault` [out]

Receives the default value of the property.

### `pCapsFlags` [out]

Receives one or more members of the [VideoProcAmpFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampflags) enumeration, indicating whether the property is controlled automatically, manually, or both.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_PROP_ID_UNSUPPORTED** | The device does not support this property. |
| **S_OK** | No error. |

## See also

[Configure the Video Quality](https://learn.microsoft.com/windows/desktop/DirectShow/configure-the-video-quality)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideoprocamp)