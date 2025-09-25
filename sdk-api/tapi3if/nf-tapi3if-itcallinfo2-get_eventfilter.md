# ITCallInfo2::get_EventFilter

## Description

The
**get_EventFilter** method gets the event filter information applicable to this call.

## Parameters

### `TapiEvent` [in]

The
[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) descriptor of event type information being checked.

### `lSubEvent` [in]

Subevent descriptor.

### `pEnable` [out]

VARIANT_TRUE if notifications are being sent on this event type for this call.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITCallInfo2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo2)