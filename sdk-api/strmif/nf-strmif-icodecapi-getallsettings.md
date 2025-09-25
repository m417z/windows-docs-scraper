# ICodecAPI::GetAllSettings

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetAllSettings** method gets the codec's current properties and writes them to a stream.

## Parameters

### `__MIDL__ICodecAPI0000` [in]

Pointer to the **IStream** interface of the stream.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

Codecs that implement [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi) are not required to support this method.

To load the properties from the stream back onto the codec, call [ICodecAPI::SetAllSettings](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-setallsettings) or [ICodecAPI::SetAllSettingsWithNotify](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-setallsettingswithnotify).

The format of the data that is written to the stream depends on the implementation of the codec. There is no standard serialization format. An application should not attempt to save the properties from one codec and load them on a different codec.

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)