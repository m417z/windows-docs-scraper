# IXMLHTTPRequest3::SetClientCertificate

## Description

Sets a client certificate to be used to authenticate against the URL specified in the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-open) method.

## Parameters

### `cbClientCertificateHash` [in]

The number of bytes of *pbClientCertHash* parameter.

### `pbClientCertificateHash` [in]

The thumbprint or hash completed over the complete client certificate being set on the HTTPS request.

### `pwszPin` [in]

This parameter is reserved.

## Return value

Returns S_OK on success.

## See also

[IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-open)