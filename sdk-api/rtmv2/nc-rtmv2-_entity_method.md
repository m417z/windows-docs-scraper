# _ENTITY_METHOD callback function

## Description

The
**RTM_ENTITY_EXPORT_METHOD** callback is the prototype for any method exported by a client.

## Parameters

### `CallerHandle`

Handle to the calling client.

### `CalleeHandle`

Handle to the client being called.

### `Input`

Handle to the method to be invoked. Contains an input buffer.

### `Output`

An array of
[RTM_ENTITY_METHOD_OUTPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_output) structures. Each structure consists of a (method identifier, correct output) tuple.

## Remarks

Methods can be exported when a client registers. Other clients, such as routing protocols, can invoke these methods to obtain client-specific information. For example, BGP can use a method to obtain OSFP information.

## See also

[RTM_ENTITY_METHOD_INPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_input)

[RTM_ENTITY_METHOD_OUTPUT](https://learn.microsoft.com/windows/desktop/api/rtmv2/ns-rtmv2-rtm_entity_method_output)