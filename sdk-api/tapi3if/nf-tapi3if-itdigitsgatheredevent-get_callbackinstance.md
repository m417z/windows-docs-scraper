# ITDigitsGatheredEvent::get_CallbackInstance

## Description

The
**get_CallbackInstance** method gets a pointer to the application's callback function that will process the event.

## Parameters

### `plCallbackInstance` [out]

Pointer to the callback instance returned by
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCallbackInstance* parameter is not a valid pointer. |

## See also

[ITDigitsGatheredEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitsgatheredevent)