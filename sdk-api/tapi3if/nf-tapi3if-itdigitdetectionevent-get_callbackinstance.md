# ITDigitDetectionEvent::get_CallbackInstance

## Description

The
**get_CallbackInstance** method gets a pointer to the callback instance associated with the event.

## Parameters

### `plCallbackInstance` [out]

Pointer to the callback instance returned by
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plCallbackInstance* parameter is not a valid pointer. |

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITDigitDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitdetectionevent)

[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications)