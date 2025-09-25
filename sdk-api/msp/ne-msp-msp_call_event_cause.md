# MSP_CALL_EVENT_CAUSE enumeration

## Description

The **MSP_CALL_EVENT_CAUSE** constant is returned within the
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) struct by the
[GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent) method when
[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event) is ME_CALL_EVENT.

## Constants

### `CALL_CAUSE_UNKNOWN:0`

Call event cause is unknown.

### `CALL_CAUSE_BAD_DEVICE`

A bad device caused failure, for either STREAM_FAIL or TERMINAL_FAIL.

### `CALL_CAUSE_CONNECT_FAIL`

Either connecting the stream failed or connecting the terminal failed. Note that if a terminal cannot be connected to a stream, the application will get a TERMINAL_FAIL event with CMC_CONNECT_FAIL. If this stream failed because the terminal is the only one to use, the application will also get a STREAM_FAIL event with CMC_CONNECT_FAIL.

### `CALL_CAUSE_LOCAL_REQUEST`

The event is the result of the application calling a method on the stream.

### `CALL_CAUSE_REMOTE_REQUEST`

The event is the result of the remote endpoint's request.

### `CALL_CAUSE_MEDIA_TIMEOUT`

The media that carries the stream is temporarily not available.

### `CALL_CAUSE_MEDIA_RECOVERED`

The media that carries the stream is back to normal from a temporary denial of service.

### `CALL_CAUSE_QUALITY_OF_SERVICE`

## See also

[ITMSPAddress::GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent)

[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event)

[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)