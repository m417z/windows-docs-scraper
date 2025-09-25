# ITTerminal::get_State

## Description

The
**get_State** method gets the current state of the terminal.

## Parameters

### `pTerminalState` [out]

Pointer to a
[TERMINAL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_state) enum member.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pTerminalState* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)

[TERMINAL_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_state)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)