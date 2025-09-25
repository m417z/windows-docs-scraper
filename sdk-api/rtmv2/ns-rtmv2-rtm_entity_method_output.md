# RTM_ENTITY_METHOD_OUTPUT structure

## Description

The
**RTM_ENTITY_METHOD_OUTPUT** structure is used to pass information to the calling client when the routing table manager invokes a method.

## Members

### `MethodType`

Specifies the method identifier.

### `MethodStatus`

Receives the status of the method after execution.

### `OutputSize`

Specifies the size, in bytes, of **OutputData**.

### `OutputData`

Buffer for data returned by the method.

## See also

[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod)