# ITTerminalControl::ConnectTerminal

## Description

The
**ConnectTerminal** method connects filters and returns a set of pins for connection. Enters each of the internal filters into the filter graph, connects the internal filters together (if applicable) and returns a set of pins for connection.

## Parameters

### `pGraph` [in]

Pointer to graph builder interface.

### `dwTerminalDirection` [in]

Indicator of
[terminal direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

### `pdwNumPins` [in, out]

Pointer to number of pins.

### `ppPins` [out]

Pointer to array of pins to be used for media transport related to the current terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **TAPI_E_NOTENOUGHMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TERMINALINUSE** | The current terminal is already in use. |

## See also

[ITTerminalControl](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalcontrol)