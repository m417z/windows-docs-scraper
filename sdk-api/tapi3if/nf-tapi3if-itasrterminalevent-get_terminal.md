# ITASRTerminalEvent::get_Terminal

## Description

The
**get_Terminal** method returns a pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface for the terminal on which the event occurred.

## Parameters

### `ppTerminal` [out]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITASRTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itasrterminalevent)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)