# ICodecAPI::IsModifiable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IsModifiable** method queries whether a codec property can be changed, given the codec's current configuration.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the property. For a list of standard codec properties, see [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The value of this property cannot be changed. |
| **S_OK** | The value of this property can be changed. |

## Remarks

Any errors besides those in the previous table indicate an inability to process the call.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)