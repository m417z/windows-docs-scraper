# CALL_MEDIA_EVENT enumeration

## Description

The
**CALL_MEDIA_EVENT** enum describes call media events. The
[ITCallMediaEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallmediaevent-get_event) method returns a member of this enum to indicate the type of call media event that occurred.

## Constants

### `CME_NEW_STREAM:0`

A new media stream has been created.

### `CME_STREAM_FAIL`

A media stream or stream request has failed.

### `CME_TERMINAL_FAIL`

A terminal has failed.

### `CME_STREAM_NOT_USED`

The media stream has not been used.

### `CME_STREAM_ACTIVE`

The media stream is active.

### `CME_STREAM_INACTIVE`

The media stream is not active.

### `CME_LASTITEM`

## Remarks

Due to latency, stream events may continue for a few seconds after a stream or related call session has been torn down.

## See also

[ITCallMediaEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallmediaevent-get_event)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)