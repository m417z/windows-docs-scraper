# ITToneDetectionEvent::get_CallbackInstance

## Description

The
**get_CallbackInstance** method gets a pointer to the application's callback function that will process the event.

## Parameters

### `plCallbackInstance` [out]

Pointer to the callback instance returned by the
[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications) method.

## Return value

This method can return one of these values.

| Return code/value | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCallbackInstance* parameter is not a valid pointer. |
| 8 | LegacyMediaControl2 Enums |

## See also

[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications)

[ITToneDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittonedetectionevent)