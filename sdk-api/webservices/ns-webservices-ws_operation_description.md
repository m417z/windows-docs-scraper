# WS_OPERATION_DESCRIPTION structure

## Description

Metadata for the service operation.

## Members

### `versionInfo`

Defines the version information. Currently value is 1.

### `inputMessageDescription`

The description of incoming [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) for a given service operation.

### `outputMessageDescription`

The description of outgoing [WS_MESSAGE](https://learn.microsoft.com/windows/desktop/wsw/ws-message) for a given service operation. For one way operations this should be **NULL**.

### `inputMessageOptions`

Provides additional flags for the in message of the operation. See [WS_SERVICE_OPERATION_MESSAGE_OPTION](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_charset) for
a list of flags. If no flags are needed, this may be 0.

[WS_SERVICE_OPERATION_MESSAGE_NILLABLE_ELEMENT](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_charset) is not applicable to [WS_RPC_LITERAL_OPERATION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_operation_style) style
operations. The input parameter must be with type of [WS_PARAMETER_TYPE_MESSAGES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_parameter_type).

### `outputMessageOptions`

Provides additional flags for the out message of the operation. See [WS_SERVICE_OPERATION_MESSAGE_OPTION](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_charset) for
a list of flags. If out message is not available, or no flags are needed, this may be 0.

[WS_SERVICE_OPERATION_MESSAGE_NILLABLE_ELEMENT](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_charset) is not applicable to [WS_RPC_LITERAL_OPERATION](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_operation_style) style
operations. The output parameter must be with type of [WS_PARAMETER_TYPE_MESSAGES](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_parameter_type).

### `parameterCount`

The number of parameters on the given service operation.

### `parameterDescription`

An array defining the individual parameters.

### `stubCallback`

A pointer to the stub function for the given operation to which the service model will delegate
to do the service operation call. This will be **NULL** for proxies.

### `style`