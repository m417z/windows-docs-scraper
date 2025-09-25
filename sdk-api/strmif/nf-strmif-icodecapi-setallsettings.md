# ICodecAPI::SetAllSettings

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAllSettings** method reads codec properties from a stream and sets them on the codec.

## Parameters

### `__MIDL__ICodecAPI0001` [in]

Pointer to the **IStream** interface of the stream.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Codecs that implement [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi) are not required to support this method.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)

[ICodecAPI::GetValue](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-getvalue)