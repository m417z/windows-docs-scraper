# ITStream::StopStream

## Description

The
**StopStream** method stops the stream.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **TAPI_E_NOTSUPPORTED** | The provider does not support this operation. |

## Remarks

An application can call this method to stop a stream. The difference between pausing a stream and stopping a stream depends on the type of transport used for the call.

This call generates events that the application can retrieve if it has registered. Please see the
[Events](https://learn.microsoft.com/windows/desktop/Tapi/events) overview for information on receiving events.

If the stream stops successfully, the application receives a
[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event) with a value of CME_STREAM_INACTIVE event and
[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause) equaling CMC_LOCAL_REQUEST.

If the stream fails to pause, the application receives a CME_STREAM_FAIL event with cause CMC_LOCAL_REQUEST.

To subsequently restart the stream, the application must call
[StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream).

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)