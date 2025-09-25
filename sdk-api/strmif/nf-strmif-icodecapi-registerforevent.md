# ICodecAPI::RegisterForEvent

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **RegisterForEvent** method registers the application to receive events from the codec.

## Parameters

### `Api` [in]

Pointer to a GUID that specifies the event.
There are three categories of events:

| Value | Meaning |
| --- | --- |
| **CODECAPI_CHANGELISTS** | The codec notifies the application when the properties of the codec change. The event data is a list of GUIDs for the properties that changed. |
| **One of the property GUIDs defined in codecapi.h. (See [Codec API Properties](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-properties).)** | The codec notifies the application when the specified property changes. Typically, a codec will support this type of notification for a limited set of properties, if any. |
| **A proprietary event GUID defined by the codec.** | Implementation dependent. |

### `userData` [out]

Pointer to caller-defined data. The application receives this pointer in the *lParam1* event parameter.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. The codec does not support event notification, or does not support the event GUID specified in the *Api* parameter. |

## Remarks

The application receives an [EC_CODECAPI_EVENT](https://learn.microsoft.com/windows/desktop/DirectShow/ec-codecapi-event) event notification whenever the encoder codec sends the event. To get the event, uses the [IMediaEventEx](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediaeventex) interface.

The *lParam2* parameter of the event is a pointer to a [CodecAPIEventData](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-codecapieventdata) structure. This structure can be followed by additional data, depending on the event GUID. The size of this data is given by the **dataLength** member.

| GUID | Event Data |
| --- | --- |
| CODECAPI_CHANGELISTS | An array of GUIDs. Each GUID specifies a codec property whose current value or valid range has changed. The size of the array is **dataLength** / `sizeof(GUID)`. |
| A property GUID defined in codecapi.h. | None. |
| Proprietary event GUID. | Implementation dependent. |

If the codec does not support the specified event, the method returns **E_NOTIMPL**. The codec might support other events.

To disable notifications for an event, call [ICodecAPI::UnregisterForEvent](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-icodecapi-unregisterforevent).

## See also

[Codec API Reference](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-reference)

[Encoder API](https://learn.microsoft.com/windows/desktop/DirectShow/encoder-api)

[ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)