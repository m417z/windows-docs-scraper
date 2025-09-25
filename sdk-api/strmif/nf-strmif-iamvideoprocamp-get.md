# IAMVideoProcAmp::Get

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Get` method gets the current setting of a video property.

## Parameters

### `Property` [in]

Specifies the property to retrieve, as a value from the [VideoProcAmpProperty](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampproperty) enumeration.

### `lValue` [out]

Receives the value of the property.

### `Flags` [out]

Receives a member of the [VideoProcAmpFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videoprocampflags) enumeration. The returned value indicates whether the setting is controlled manually or automatically.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Configure the Video Quality](https://learn.microsoft.com/windows/desktop/DirectShow/configure-the-video-quality)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideoprocamp)

[IAMVideoProcAmp::Set](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideoprocamp-set)