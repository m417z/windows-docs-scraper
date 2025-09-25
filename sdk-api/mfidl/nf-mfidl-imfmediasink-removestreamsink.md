# IMFMediaSink::RemoveStreamSink

## Description

Removes a stream sink from the media sink.

## Parameters

### `dwStreamSinkIdentifier` [in]

Identifier of the stream to remove. The stream identifier is defined when you call [IMFMediaSink::AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink) to add the stream sink.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | This particular stream sink cannot be removed. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream number is not valid. |
| **MF_E_NOT_INITIALIZED** | The media sink has not been initialized. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |
| **MF_E_STREAMSINKS_FIXED** | This media sink has a fixed set of stream sinks. Stream sinks cannot be removed. |

## Remarks

After this method is called, the corresponding stream sink object is no longer valid. The [IMFMediaSink::GetStreamSinkByIndex](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getstreamsinkbyindex) and [IMFMediaSink::GetStreamSinkById](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getstreamsinkbyid) methods will no longer return that stream sink. You can re-use the stream identifier if you add another stream (by calling [AddStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-addstreamsink)).

Not all media sinks support this method. If the media sink does not support this method, the [IMFMediaSink::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getcharacteristics) method returns the MEDIASINK_FIXED_STREAMS flag.

In some cases, the media sink supports this method but does not allow every stream sink to be removed. (For example, it might not allow stream 0 to be removed.)

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)