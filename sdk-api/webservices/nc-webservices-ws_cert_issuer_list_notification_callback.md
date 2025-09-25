# WS_CERT_ISSUER_LIST_NOTIFICATION_CALLBACK callback function

## Description

Notifies the client of the list of certificate issuers
that are acceptable to the server. With some protocols such as SSL,
the server may optionally send such an issuer list to help the client
choose a certificate.

This callback is an optional part of the [WS_CUSTOM_CERT_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_cert_credential).
If the (possibly **NULL**) certificate returned by the [WS_GET_CERT_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_get_cert_callback) is
accepted by the server, then this callback is never invoked. If the
server rejects it and sends back an issuer list, then this callback
will be invoked. The client may then choose a certificate based on
the issuer list and supply that certificate when the channel is opened
next and *WS_GET_CERT_CALLBACK* is invoked again.

The parameters supplied during this callback are valid only for the
duration of the callback.

## Parameters

### `certIssuerListNotificationCallbackState` [in]

State that was specified along with this callback in the [WS_CUSTOM_CERT_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_cert_credential).

### `issuerList` [in]

The list of certificate issuers acceptable to the server.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.