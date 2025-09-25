# ITCallInfoChangeEvent::get_CallbackInstance

## Description

The
**get_CallbackInstance** method gets a pointer to the callback instance associated with this event.

## Parameters

### `plCallbackInstance` [out]

Pointer to callback instance returned by
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

[ITCallInfoChangeEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfochangeevent)

[ITTAPI::RegisterCallNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-registercallnotifications)