# ITStream::StartStream

## Description

The
**StartStream** method starts the stream.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **TAPI_E_NOTERMINALSELECTED** | No terminal has been selected on the stream, so it cannot be started. |
| **TAPI_E_NOTSTOPPED** | Stream has already been started. |

## Remarks

Streams start automatically as soon as a call is connected and ready to stream and a terminal is selected. Therefore, most applications do not need to call this method. Applications have to call this method only to start a stream that the application has previously stopped or paused by calling
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITStream::PauseStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-pausestream).

This call generates events that the application can retrieve if it has registered. Please see the
[Events](https://learn.microsoft.com/windows/desktop/Tapi/events) overview for information on receiving events.

If the stream starts successfully, the MSP fires a
[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event) with a value of CME_STREAM_ACTIVE event and
[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause) equaling CMC_LOCAL_REQUEST.

If the stream fails to pause, the MSP fires a CME_STREAM_FAIL event with cause CMC_LOCAL_REQUEST.

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)