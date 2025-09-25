# XHR_CERT_IGNORE_FLAG enumeration

## Description

Defines flags that you can assign to an outgoing HTTP request to ignore certain certificate errors by calling the [SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty) method on the [IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3) interface.

## Constants

### `XHR_CERT_IGNORE_REVOCATION_FAILED:0x80UL`

Ignore certificate revocation errors.

### `XHR_CERT_IGNORE_UNKNOWN_CA:0x100UL`

Ignore a certificate error for an unknown or invalid certificate authority.

### `XHR_CERT_IGNORE_CERT_CN_INVALID:0x1000UL`

Ignore a certificate error caused by an invalid common name. This allows an invalid common name in a certificate where the server name specified by the app for the requested URL does not match the common name in the server certificate.

### `XHR_CERT_IGNORE_CERT_DATE_INVALID:0x2000UL`

Ignore a certificate error caused by an invalid date in the certificate. This allows certificates that are expired or not yet effective.

### `XHR_CERT_IGNORE_ALL_SERVER_ERRORS`

Ignore all server certificate errors.

## See also

[IXMLHTTPRequest3](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3)

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)