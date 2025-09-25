# ITCallHub::EnumerateCalls

## Description

The
**EnumerateCalls** method enumerates calls currently associated with the call hub. This method is provided for C and C++ applications. Automation client applications, such as those written in Visual Basic, must use the
[get_Calls](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallhub-get_calls) method.

## Parameters

### `ppEnumCall` [out]

Pointer to
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to create the enumerator. |
| **E_POINTER** | The *ppEnumCall* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumcall) interface returned by **ITCallHub::EnumerateCalls**. The application must call **Release** on the
**IEnumCall** interface to free resources associated with it.

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub)