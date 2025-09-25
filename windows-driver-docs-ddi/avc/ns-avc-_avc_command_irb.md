# _AVC_COMMAND_IRB structure

## Description

The AVC_COMMAND_IRB structure defines a structure that contains an AV/C command and response pair.

## Members

### `Common`

This must be set to the **AVC_FUNCTION_COMMAND** enumerator from the AVC_FUNCTION enumeration.

### `SubunitAddrFlag`

This is a flag indicating if the **SubunitAddr** member specifies an address. Set to one if it does, otherwise set to zero.

### `AlternateOpcodesFlag`

This is a flag indicating if the **AlternateOpcodes** member is valid. Set to one if it is, otherwise set to zero.

### `TimeoutFlag`

Set this to one if the default time-out is not appropriate for the subunit. If this is set, the **Timeout** member must be set to the desired time-out (in 100-ns units).

### `RetryFlag`

Set this to one if the default retry count is not appropriate for the subunit. If this is set, the **Retries** member must be set to the desired retry count.

### `CommandType`

This specifies a value from the AvcCommandType enumeration. This member is used only during AVC_FUNCTION_GET_REQUEST. It is ignored otherwise.

### `ResponseCode`

This specifies a value from the AvcResponseCode enumeration. This member is used only during AVC_FUNCTION_SEND_RESPONSE. It is ignored otherwise.

### `SubunitAddr`

Set this to the address of nonpaged memory containing the desired subunit address encoded according to Section 5.3.3 of the AV/C Digital Interface Command Set General Specification, Rev 3.0. No length is necessary because the subunit address encoding implies this. This parameter is ignored if **SubunitAddrFlag** is zero.

### `AlternateOpcodes`

Set this to the address of nonpaged memory containing the desired alternate opcode list. The first byte of the opcode list is the count of opcodes to follow (equivalent to the number of bytes). The total length of the memory containing the alternate opcode list is AlternateOpcodes[0]+1. This parameter is ignored if **AlternateOpcodesFlag** is zero.

### `Timeout`

Set this to the desired time-out in 100-ns units. For example, the default time-out value is: **Timeout.QuadPart** = 1000000 (100ms in 100ns units). This parameter is ignored if **TimeoutFlag** is zero.

### `Retries`

Set this to the desired number of times *avc.sys* should attempt to retry requests after each time-out without a response. Note that a retry count of zero means that the request is tried once. The total amount of time spent trying to process a command without getting a response is Timeout * (Retries + 1). This parameter is ignored if **RetryFlag** is zero.

### `Opcode`

Set this to the desired AV/C opcode (appropriate for the subunit type). This is a required parameter. On response, if **AlternateOpcodesFlag** was set, and one of the alternate opcodes was used to match the response, this is set to that alternate opcode.

### `OperandLength`

Set this to the number of bytes used to store the operands in the **Operands** member. This is a required parameter. On response, this parameter is set to the number of bytes in the operand list used by the response.

### `Operands`

Set this to the operand list appropriate for the subunit type and opcode. This is a required parameter. On response, this parameter contains the operand list of the response.

### `NodeAddress`

Reserved. This member must be zero.

### `Generation`

Reserved. This member must be zero.

## Remarks

This structure is used with the [AVC_FUNCTION_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-command), [AVC_FUNCTION_GET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-request) and [AVC_FUNCTION_SEND_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-send-response) function codes.

## See also

[AVC_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/ne-avc-_tagavc_function)

[AVC_FUNCTION_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-command)

[AVC_FUNCTION_GET_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-request)

[AVC_FUNCTION_SEND_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-send-response)