## Description

The **CodecAPIEventData** structure contains event data for the [EC_CODECAPI_EVENT](https://learn.microsoft.com/windows/desktop/DirectShow/ec-codecapi-event) event. This event is sent by codecs that support the [ICodecAPI](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi) interface.

## Members

### `guid`

A GUID that identifies the codec event.

### `dataLength`

The length of the additional data that follows this structure, in bytes.
The value can be zero.

### `reserved`

Reserved; do not use.

## Remarks

This structure may be followed by addition data, depending on the codec event. For more information, see [ICodecAPI::RegisterForEvent](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-registerforevent).

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[ICodecAPI::RegisterForEvent](https://learn.microsoft.com/windows/desktop/api/icodecapi/nf-icodecapi-icodecapi-registerforevent)