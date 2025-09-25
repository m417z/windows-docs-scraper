# ITAddress::EnumerateCalls

## Description

The
**EnumerateCalls** method enumerates calls on the current address. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Calls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_calls) method.

## Parameters

### `ppCallEnum` [out]

Pointer to an
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCallEnum* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface returned by **ITAddress::EnumerateCalls**. The application must call **Release** on the
**IEnumCall** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall)

[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress)

[ITAddress::get_Calls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-get_calls)