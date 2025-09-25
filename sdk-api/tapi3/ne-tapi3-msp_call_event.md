# MSP_CALL_EVENT enumeration

## Description

The **MSP_CALL_EVENT** constant is returned within the
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) struct by the
[GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent) method when
[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event) is ME_CALL_EVENT.

## Constants

### `CALL_NEW_STREAM:0`

A new stream is created by the call. The application can choose to select a terminal or delete the stream from the call.

### `CALL_STREAM_FAIL`

Setup of the stream failed or the stream fails to start.

### `CALL_TERMINAL_FAIL`

The terminal failed to connect.

### `CALL_STREAM_NOT_USED`

The stream is not used in the call (the remote party rejected it).

### `CALL_STREAM_ACTIVE`

The application needs this event to decide when a stream can be used to send and receive data. It is fired when the streams enter running state (the timing of which is determined by the TSP).

### `CALL_STREAM_INACTIVE`

No more data can be sent to or received from this stream. This happens when a send stream has sent all its data, or when a receive stream stops receiving data.

## See also

[ITMSPAddress::GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent)

[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event)

[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)