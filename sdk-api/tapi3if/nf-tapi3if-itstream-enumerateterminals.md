# ITStream::EnumerateTerminals

## Description

The
**EnumerateTerminals** method enumerates terminals selected on the stream. Provided for C and C++ applications. Automation client applications such as Visual Basic must use the
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

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal) interface returned by **ITStream::EnumerateTerminals**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**IEnumTerminal** interface to free resources associated with it.

## See also

[IEnumTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumterminal)

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)