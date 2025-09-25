# IAMVideoProcAmp::Set

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Set** method sets video quality for a specified property.

## Parameters

### `Property` [in]

The property to set, specified as a [VideoProcAmpProperty](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampproperty) enumeration value.

### `lValue` [in]

The new value of the property.

### `Flags` [in]

The desired control setting, specified as a [VideoProcAmpFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampflags) enumeration
value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *Flags* parameter is **VideoProcAmp_Flags_Auto**, the *lValue* parameter is ignored, as long as it's between the minimum and maximum values of the property.

## See also

[Configure the Video Quality](https://learn.microsoft.com/windows/desktop/DirectShow/configure-the-video-quality)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideoprocamp)

[IAMVideoProcAmp::Get](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideoprocamp-get)