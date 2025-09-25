# ITTerminal::get_TerminalType

## Description

The
**get_TerminalType** method gets the
[TERMINAL_TYPE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_type) of the terminal.

## Parameters

### `pType` [out]

Pointer to a
[TERMINAL_TYPE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_type).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pType* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[TERMINAL_TYPE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_type)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)