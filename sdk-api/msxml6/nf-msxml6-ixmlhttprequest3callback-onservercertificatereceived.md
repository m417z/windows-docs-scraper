# IXMLHTTPRequest3Callback::OnServerCertificateReceived

## Description

Occurs when a client receives certificate errors or a server certificate chain during SSL negotiation with the server.

## Parameters

### `pXHR` [in]

The initial HTTP request.

### `dwCertificateErrors` [in]

The certificate errors encountered in the HTTPS connection (see XHR_CERT_ERROR_FLAG).

### `cServerCertificateChain` [in]

The number of elements in the *rgServerCertChain* parameter.

### `rgServerCertificateChain` [in]

An array of [XHR_CERT](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cert) structures that represent the server certificate chain.

## Return value

Returns **S_OK** on success.

## Remarks

**Note** This callback method must not throw exceptions.

## See also

[IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3)

[IXMLHTTPRequest3Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3callback)

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)

[XHR_CERT](https://learn.microsoft.com/windows/desktop/api/msxml6/ns-msxml6-xhr_cert)

[XHR_CERT_ERROR_FLAG](https://learn.microsoft.com/windows/desktop/api/msxml6/ne-msxml6-xhr_cert_error_flag)