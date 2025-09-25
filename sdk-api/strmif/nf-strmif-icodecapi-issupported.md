# ICodecAPI::IsSupported

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IsSupported** method queries whether a codec supports a given property.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property to query. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The codec does not support the property. |
| **S_OK** | The codec supports the property. |
| **E_NOTIMPL** | The codec does not support the property. |

## Remarks

Any errors besides those in the previous table indicate an inability to process the call.

**Note** If the codec does not support the property, the method can return either **S_FALSE** or **E_NOTIMPL**. The value **E_NOTIMPL** is preferred, but earlier documentation listed only **S_FALSE**, so some codecs might return that value. Applications should explicitly test for the value **S_OK**.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)