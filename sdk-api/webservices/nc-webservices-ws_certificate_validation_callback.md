# WS_CERTIFICATE_VALIDATION_CALLBACK callback function

## Description

The *WS_CERTIFICATE_VALIDATION_CALLBACK* callback is invoked to validate a certificate when a connection to an HTTP server has been established and headers sent.

## Parameters

### `certContext` [in]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that is associated with the connection. Applications must free this structure using [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext).

### `state` [in, optional]

A pointer to application specific state information. This parameter corresponds to the **state** member of the [WS_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_certificate_validation_callback_context) structure.

## Return value

This callback function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The certificate validated successfully. |
| **Other Errors** | This function may return other errors not listed above. |

## Remarks

If *WS_CERTIFICATE_VALIDATION_CALLBACK* returns any value other than **S_OK**, the channel will be aborted. The service proxy will also be aborted if this property was passed to [WsCreateServiceProxy](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wscreateserviceproxy).

The callback implementation must avoid long computation times or long blocking calls so that it returns to the caller quickly.

## See also

[WS_CERTIFICATE_VALIDATION_CALLBACK_CONTEXT](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_certificate_validation_callback_context)