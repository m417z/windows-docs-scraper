# ITSubStream::SelectTerminal

## Description

The
**SelectTerminal** method selects an
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) object onto the substream. See the Remarks section under
[ITStream::SelectTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-selectterminal) for additional information.

## Parameters

### `pTerminal` [in]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface of selected terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_MAXTERMINALS** | Multiple terminals have been selected on the substream, but media mixing or splitting is not possible. |
| **TAPI_E_INVALIDTERMINAL** | The terminal selected is not valid. |

## See also

[ITStream::SelectTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-selectterminal)

[ITSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itsubstream)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)