# RTM_ENTITY_METHOD_INPUT structure

## Description

The
**RTM_ENTITY_METHOD_INPUT** structure is used to pass information to a client when invoking its method.

## Members

### `MethodType`

Specifies the method.

### `InputSize`

Specifies the size, in bytes, of **InputData**.

### `InputData`

Buffer for input data for the method.

## See also

[RtmInvokeMethod](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtminvokemethod)