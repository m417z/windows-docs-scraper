# _tagAvcCommandType enumeration

## Description

The AvcCommandType enumeration type is used to indicate the type of command issued by a subunit driver to its AV/C subunit through **AVC_FUNCTION_COMMAND** or **AVC_FUNCTION_GET_REQUEST** function codes.

## Constants

### `AVC_CTYPE_CONTROL`

Specifies a control type of command.

### `AVC_CTYPE_STATUS`

Specifies a status type of command.

### `AVC_CTYPE_SPEC_INQ`

Specifies a specific-inquiry type of command. This permits a controller to inform targets that a specific set of operands must by furnished along with the opcode when issuing a command.

### `AVC_CTYPE_NOTIFY`

Specifies a notify type of command.

### `AVC_CTYPE_GEN_INQ`

Specifies a general inquiry command type. This permits a controller to query a target to find out if it supports a specific opcode without needing to pass any specific operands.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-command)

[AVC_FUNCTION_GET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-request)