# WS_GET_CERT_CALLBACK callback function

## Description

Provides a certificate to the security runtime. This
callback is specified as part of the [WS_CUSTOM_CERT_CREDENTIAL](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_cert_credential),
which in turn may be specified as part of a security binding that requires a
certificate credential. The runtime will invoke this callback when the channel
(client-side) or the listener (server-side) is opened.

Cert ownership: If this callback returns a success HRESULT, the caller
(namely, the security runtime) will take ownership of the returned
certificate, and will free it when the containing channel no longer
needs it. If this callback returns a failure HRESULT, the caller will
NOT take ownership of, or even look at, the value returned in the out
parameter 'cert'.

## Parameters

### `getCertCallbackState` [in]

State that was specified along with this callback in the certificate credential.

### `targetAddress` [in, optional]

The target address to whom this certificate is to be presented, in
case this certificate credential is specified for a client.

### `viaUri` [in, optional]

The via address to whom this certificate is to be presented.

#### - **cert

The location to return the certificate.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

### `cert`

The location to return the certificate.

## Return value

This callback function does not return a value.