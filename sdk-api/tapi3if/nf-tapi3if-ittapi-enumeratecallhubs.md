# ITTAPI::EnumerateCallHubs

## Description

The
**EnumerateCallHubs** method enumerates the currently available call hubs. Provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Callhubs](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-get_callhubs) method.

## Parameters

### `ppEnumCallHub` [out]

Pointer to the
[IEnumCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallhub) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumCallHub* parameter is not a valid pointer. |
| **E_INVALIDARG** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **Addref** method on the
[IEnumCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallhub) interface returned by **ITTAPI::EnumerateCallHubs**. The application must call **Release** on the
**IEnumCallHub** interface to free resources associated with it.

## See also

[IEnumCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcallhub)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)