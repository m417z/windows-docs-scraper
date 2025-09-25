# ITCallInfo::get_CallHub

## Description

The
**get_CallHub** method gets a pointer to the
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface of the
[CallHub object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object).

## Parameters

### `ppCallHub` [out]

Pointer to
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface of the CallHub object.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_PENDING** | Call hub not yet available. |
| **E_POINTER** | The *ppCallHub* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

On some service providers, the call hub is not available until after the call is made.

TAPI calls the **AddRef** method on the
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface returned by **ITCallInfo::get_CallHub**. The application must call **Release** on the
**ITCallHub** interface to free resources associated with it.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[CallHub object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)