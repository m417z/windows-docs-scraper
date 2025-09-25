# ITSubStream::get_Terminals

## Description

The
**get_Terminals** method creates a collection of terminals associated with the current substream. Provided for Automation client applications, such as those written in Visual Basic. C and C++ applications must use the
[EnumerateTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-enumerateterminals) method.

## Parameters

### `pTerminals` [out]

Pointer to **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface pointers (terminal objects).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminals* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method returns only the terminals selected on the substream. Other terminals may be selected on the stream or on other substreams within the stream; those terminals are not returned.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITSubStream::get_Terminals**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITTerminal** interface to free resources associated with it.

## See also

[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection)

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)