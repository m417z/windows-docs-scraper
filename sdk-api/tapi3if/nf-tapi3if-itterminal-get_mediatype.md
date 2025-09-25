# ITTerminal::get_MediaType

## Description

The
**get_MediaType** method determines the media that this terminal supports.

## Parameters

### `plMediaType` [out]

Pointer to
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plMediaType* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)