# WS_PARAMETER_DESCRIPTION structure

## Description

The index of the parameters in the incoming/outgoing messages field descriptions.

## Members

### `parameterType`

The type of the parameter.

### `inputMessageIndex`

A value between 0 and MAX_SHORT - 1 that represents the index of the field
in the input [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message). It is MAX_USHORT if it has not present in the input
WS_MESSAGE.

### `outputMessageIndex`

A value between 0 and MAX_SHORT - 1 that represents the index of the field
in the output [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message). It is MAX_USHORT if it has not present in the output
WS_MESSAGE.