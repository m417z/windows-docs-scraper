# ITAddressEvent::get_Event

## Description

The
**get_Event** method gets the
[ADDRESS_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_event) descriptor of an event.

## Parameters

### `pEvent` [out]

Pointer to the
[ADDRESS_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_event) descriptor of an event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pEvent* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pEvent* parameter is not a valid pointer. |

## Remarks

Certain events on PnP devices, such as AE_NEWTERMINAL and AE_REMOVETERMINAL, will not be received until after the first time static terminals are enumerated using
[ITTerminalSupport::EnumerateStaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratestaticterminals) or
[ITTerminalSupport::get_StaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_staticterminals).

## See also

[ADDRESS_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-address_event)

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressevent)