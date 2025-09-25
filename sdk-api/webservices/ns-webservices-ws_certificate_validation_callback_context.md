# WS_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT structure

## Description

The **WS_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT** structure contains the callback function and state for validating the certificate for an HTTP connection.

## Members

### `callback`

A [WS_CERTIFICATE_VALIDATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_certificate_validation_callback) callback that is an application specific callback for validating HTTP certificates.

### `state`

Application specific state that is made available to the callback when invoked.

## See also

[WS_CERTIFICATE_VALIDATION_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_certificate_validation_callback)