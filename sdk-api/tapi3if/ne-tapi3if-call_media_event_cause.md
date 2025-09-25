# CALL_MEDIA_EVENT_CAUSE enumeration

## Description

The
**CALL_MEDIA_EVENT_CAUSE** enum is used by
[ITCallMediaEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallmediaevent-get_cause) method to return a description of what caused a media event, such as a device timeout.

## Constants

### `CMC_UNKNOWN:0`

Call media is unknown.

### `CMC_BAD_DEVICE`

Device source or renderer is not functioning.

### `CMC_CONNECT_FAIL`

Could not connect to media device.

### `CMC_LOCAL_REQUEST`

A local request has been received.

### `CMC_REMOTE_REQUEST`

A remote request has been received.

### `CMC_MEDIA_TIMEOUT`

The media device timed out.

### `CMC_MEDIA_RECOVERED`

Media processing has resumed after an interruption.

### `CMC_QUALITY_OF_SERVICE`

## See also

[ITCallMediaEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallmediaevent-get_cause)