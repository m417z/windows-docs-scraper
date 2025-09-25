# ITAddress2::put_EventFilter

## Description

The
**put_EventFilter** method sets an event filter for the current address. If no event filters are set, the application will not be notified of events on this address.

## Parameters

### `TapiEvent` [in]

The
[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) descriptor of the event type.

### `lSubEvent` [in]

Subevent descriptor.

### `bEnable` [in]

VARIANT_TRUE if the application requires notification of this event type. VARIANT_FALSE if the application does not require notifications for this event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)

[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event)