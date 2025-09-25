# ITPhone::EnumeratePreferredAddresses

## Description

The
**EnumeratePreferredAddresses** method enumerates the preferred addresses for the phone object. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_Addresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_addresses) method.

## Parameters

### `ppEnumAddress` [out]

Pointer to a location where, on success, the method places a pointer to an enumeration object that contains the list of addresses. For more information, see the following Remarks section.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumAddress* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the enumeration object. |

## Remarks

If there are no usable addresses present on the system, this method produces an empty enumeration and returns S_OK.

A phone device declares itself as being preferred to an address or set of addresses by returning address/line IDs using the TAPI 2.x
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function with device class tapi/line.

Although the
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid) function requires the handle to an open phone device, the application does not have to call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before calling
**EnumeratePreferredAddresses**. This is because the implementation of the phone object can open the phone and call
**phoneGetID** during TAPI initialization or when a new phone object appears.

TAPI calls the **AddRef** method on the
[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress) interface returned by **ITPhone::EnumeratePreferredAddresses**. The application must call **Release** on the
**IEnumAddress** interface to free resources associated with it.

## See also

[EnumerateAddresses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-enumerateaddresses)

[IEnumAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumaddress)

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid)