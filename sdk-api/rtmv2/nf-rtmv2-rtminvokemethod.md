# RtmInvokeMethod function

## Description

The
**RtmInvokeMethod** function invokes a method exported by another client.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

### `EntityHandle` [in]

Handle to the client whose methods are being invoked.

### `Input` [in]

Pointer to an
[RTM_ENTITY_METHOD_INPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_input) structure that contains the method to be invoked and a common input buffer.

### `OutputSize` [in, out]

On input, *OutputSize* is a pointer to a **UINT** value that specifies the size, in bytes, of *Output*.

On output, *OutputSize* receives a pointer to a **UINT** value that specifies the actual size, in bytes, of *Output*.

### `Output` [out]

Receives a pointer to an array of
[RTM_ENTITY_METHOD_OUTPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_output) structures. Each structure consists of a (method identifier, correct output) tuple.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

For sample code using this function, see
[Obtain and Call the Exported Methods for a Client](https://learn.microsoft.com/windows/desktop/RRAS/obtain-and-call-the-exported-methods-for-a-client).

## See also

[RTM_ENTITY_METHOD_INPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_input)

[RTM_ENTITY_METHOD_OUTPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_output)

[RtmBlockMethods](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmblockmethods)

[RtmGetEntityMethods](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmgetentitymethods)