# WS_CUSTOM_CERT_CREDENTIAL structure

## Description

The type for specifying a certificate credential that is to be
supplied by a callback to the application. This callback is invoked
to get the certificate during [WsOpenChannel](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenchannel) on the client
side and during [WsOpenListener](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsopenlistener) on the server side. It is
always invoked [short](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_callback_model).

## Members

### `credential`

The base type from which this type and all other certificate credential types derive.

### `getCertCallback`

The Callback to get the certificate.

### `getCertCallbackState`

The state to be passed when invoking the callback.

### `certIssuerListNotificationCallback`

### `certIssuerListNotificationCallbackState`