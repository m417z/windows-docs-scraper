# IXMLHTTPRequest3Callback::OnClientCertificateRequested

## Description

Occurs when a client receives a request for a client certificate during SSL negotiation with the server.

## Parameters

### `pXHR` [in]

The initial HTTP request.

### `cIssuerList` [in]

The number of strings in the *rgpwszIssuerList* parameter.

### `rgpwszIssuerList` [in]

An array of strings that represent the issuer list.

## Return value

Returns **S_OK** on success.

## Remarks

**Note** This callback method must not throw exceptions.

## See also

[IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3)

[IXMLHTTPRequest3Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3callback)

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)