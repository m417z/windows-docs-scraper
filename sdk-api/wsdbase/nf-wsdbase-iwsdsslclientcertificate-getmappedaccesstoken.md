# IWSDSSLClientCertificate::GetMappedAccessToken

## Description

Gets the mapped access token.

## Parameters

### `phToken` [in, out]

A handle for the mapped access token. Upon completion, the caller must free the handle by calling [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | The token associated with the specified handle is not available. |

## Remarks

If the client certificate was successfully mapped to an operating system user account, then a valid access token for this user will be returned through *phToken*. This token can be used to impersonate the user. Internally, HTTP.sys will do the client certificate to user account mapping and return this information through the [HTTP_SSL_CLIENT_CERT_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_ssl_client_cert_info) structure.

## See also

[IWSDSSLClientCertificate](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdsslclientcertificate)