# ITAddress2::get_EventFilter

## Description

The
**get_EventFilter** method retrieves the current filter settings for the current address and a given
[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) value.

If no filters are set for an address, no event information for that address will be sent to the application.

## Parameters

### `TapiEvent` [in]

The
[TAPI_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_event) descriptor of event type information being checked.

### `lSubEvent` [in]

Subevent value. **NULL** if not applicable.

### `pEnable` [out]

Pointer to VARIANT_BOOL indicating whether the current event is required by the application.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITAddress2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress2)