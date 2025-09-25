# ITTAPIObjectEvent::get_Event

## Description

The
**get_Event** method gets information concerning an asynchronous event notification. The application uses
[TAPIOBJECT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapiobject_event) to determine what type of event is being signaled.

## Parameters

### `pEvent` [out]

[TAPIOBJECT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapiobject_event) indicator of the event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTAPIObjectEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapiobjectevent)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)

[TAPIOBJECT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapiobject_event)