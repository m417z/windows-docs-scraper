# ITStream::PauseStream

## Description

The
**PauseStream** method pauses the stream.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |

## Remarks

The difference between pausing and stopping a stream depends on the type of transport.

If the stream pauses successfully, the MSP should fire
[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event) with a value of CME_STREAM_INACTIVE and
[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause) equaling CMC_LOCAL_REQUEST.

If the stream fails to pause, the event will be CME_STREAM_FAIL with cause CMC_LOCAL_REQUEST.

A call to
[StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) restarts the stream.

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)