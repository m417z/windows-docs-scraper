# ITSubStream::PauseSubStream

## Description

The
**PauseSubStream** method pauses the substream.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_NOTSUPPORTED** | This operation is not supported. |

## Remarks

The difference between pausing and stopping a stream depends on the type of transport.

If the substream pauses successfully, the application receives a
[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event) with a value of CME_STREAM_INACTIVE and
[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause) equaling CMC_LOCAL_REQUEST.

If the substream fails to pause, the event will be CME_STREAM_FAIL with cause CMC_LOCAL_REQUEST.

A call to
[StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) restarts the substream.

## See also

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)