# ITStream::UnselectTerminal

## Description

The
**UnselectTerminal** method unselects the terminal from the stream and stops streaming for this stream.

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

Successfully unselecting the last terminal from a stream effectively ceases any existing streaming for this particular stream. Subsequently selecting the same terminal or another terminal restarts such interrupted streaming.

Reselection onto a stream with a different terminal, or a newly created one, can have unexpected effects. The filter graph may retain information from the previous terminal that fails to match the new one.

## See also

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)