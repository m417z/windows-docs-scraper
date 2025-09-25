# ITTAPI::get_CallHubs

## Description

The
**get_CallHubs** method creates a collection of the currently available call hubs. Provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateCallHubs](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-enumeratecallhubs) method.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface pointers (CallHub objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pVariant* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pVariant* parameter is not a valid pointer. |

## Remarks

TAPI calls the **Addref** method on the
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface returned by **ITTAPI::get_CallHubs**. The application must call **Release** on the
**ITCallHub** interface to free resources associated with it.

## See also

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)