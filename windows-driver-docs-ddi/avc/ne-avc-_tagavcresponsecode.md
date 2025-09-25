# _tagAvcResponseCode enumeration

## Description

The AvcResponseCode enumeration type is used to indicate the type of response received by a subunit driver from its AV/C subunit through **AVC_FUNCTION_COMMAND** or **AVC_FUNCTION_SEND_RESPONSE** function codes.

## Constants

### `AVC_RESPONSE_NOTIMPL`

Indicates the subunit does not support the specified control command.

### `AVC_RESPONSE_ACCEPTED`

Indicates the subunit does implement the specified control command and that subunit state permits execution of the command. Note: Command execution may not have completed by the time the **AVC_RESPONSE_ACCEPTED** has been returned.

### `AVC_RESPONSE_REJECTED`

Specifies a response indicating the command or request was rejected.

### `AVC_RESPONSE_IN_TRANSITION`

Specifies a response indicating the command or request was accepted.

### `AVC_RESPONSE_STABLE`

Indicates the subunit implements the command. Same meaning as AVC_RESPONSE_IMPLMENTED.

### `AVC_RESPONSE_IMPLEMENTED`

Indicates the subunit implements the command. Same meaning as AVC_RESPONSE_STABLE.

### `AVC_RESPONSE_CHANGED`

Indicates the subunit state has changed.

### `AVC_RESPONSE_INTERIM`

Indicates the subunit is unable to respond with either **AVC_RESPONSE_ACCEPTED** or **AVC_RESPONSE_REJECTED** within the 100 millisecond timeframe for responses. The subunit will ultimately return a response frame with either an **AVC_RESPONSE_ACCEPTED** or **AVC_RESPONSE_REJECTED** code.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-command)

[AVC_FUNCTION_SEND_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-send-response)