# TERMINAL_TYPE enumeration

## Description

The
**TERMINAL_TYPE** enum describes the type of the terminal. This enum is returned by the
[ITTerminal::get_TerminalType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminal-get_terminaltype) method.

## Constants

### `TT_STATIC:0`

A static terminal is a terminal that cannot be created and usually refers to hardware device. TAPI enumerates these terminals.

### `TT_DYNAMIC`

A terminal type that can be created. The application must call
[ITTerminalSupport::CreateTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-createterminal) to use this type of terminal.

## See also

[ITTerminal::get_TerminalType](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminal-get_terminaltype)