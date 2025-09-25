# ITTAPI::EnumerateAddresses

## Description

The
**EnumerateAddresses** method enumerates the addresses that are currently available. Provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Addresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-get_addresses) method.

## Parameters

### `ppEnumAddress` [out]

Pointer to the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumAddress* parameter is not a valid pointer. |
| **E_INVALIDARG** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

An application typically uses this enumeration to check the capabilities of each address and determine which are useful for current purposes.

If an expected address is not found, this may indicate that the appropriate service provider has not been installed or is not working correctly.

TAPI calls the **Addref** method on the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface returned by **ITTAPI::EnumerateAddresses**. The application must call the **Release** method on the
**IEnumAddress** interface to free resources associated with it.

If an address is created or removed during a TAPI session, the application will be notified through the
[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification) interface. If an address has been created, such as by installing a Plug and Play device, the
[ITTAPIEventNotification::Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapieventnotification-event) returns the **TE_ADDRESSCREATE** member of the
[TAPIOBJECT_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapiobject_event) enum. If an address is removed, **ITTAPIEventNotification::Event** returns **TE_ADDRESSREMOVE**. Calling
**EnumerateAddresses** after these events will reflect the current addresses.

## See also

[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[Register Events code snippet](https://learn.microsoft.com/windows/desktop/Tapi/register-events)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)

[get_Addresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-get_addresses)