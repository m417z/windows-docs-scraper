# ITSubStream::UnselectTerminal

## Description

The
**UnselectTerminal** method unselects the terminal from the substream.

## Parameters

### `pTerminal` [in]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface terminal to remove from stream.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALIDTERMINAL** | The *pTerminal* parameter does not point to a valid terminal. |
| **TAPI_E_NOTSUPPORTED** | The provider does not support this operation. |

## Remarks

Some stream events may be received after streaming has been stopped due to delayed transmission.

Successfully unselecting the last terminal from a substream effectively ceases any existing streaming for this particular substream. Subsequently selecting the same terminal or another terminal restarts such interrupted streaming.

## See also

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)