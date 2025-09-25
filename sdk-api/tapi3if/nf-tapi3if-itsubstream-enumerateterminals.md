# ITSubStream::EnumerateTerminals

## Description

The
**EnumerateTerminals** method enumerates terminals selected on the substream. Provided for C and C++ applications. Automation client applications such as Visual Basic must use the
[get_Terminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-get_terminals) method.

## Parameters

### `ppEnumTerminal` [out]

Pointer to an
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) terminal enumerator.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppEnumTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

This method returns only the terminals selected on the substream. Other terminals may be selected on the stream or on other substreams within the stream; those terminals are not returned.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface returned by **ITSubStream::EnumerateTerminals**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumTerminal** interface to free resources associated with it.

## See also

[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal)

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)