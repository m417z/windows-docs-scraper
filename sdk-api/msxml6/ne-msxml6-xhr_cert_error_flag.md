# XHR_CERT_ERROR_FLAG enumeration

## Description

Defines flags that indicate server certificate errors during SSL negotiation with the server by handling the [OnServerCertificateReceived](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest3callback-onservercertificatereceived) method on the [IXMLHTTPRequest3Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3callback) interface.

## Constants

### `XHR_CERT_ERROR_REVOCATION_FAILED:0x800000UL`

The certificate received from the server has an invalid certificate revocation.

### `XHR_CERT_ERROR_UNKNOWN_CA`

The certificate received from the server has an unknown or invalid certificate authority.

### `XHR_CERT_ERROR_CERT_CN_INVALID`

The certificate received from the server has an invalid common name.

### `XHR_CERT_ERROR_CERT_DATE_INVALID`

The certificate received from the server has an invalid certificate date.

### `XHR_CERT_ERROR_ALL_SERVER_ERRORS`

The certificate received from the server has an invalid certificate revocation, and unknown or invalid certificate authority, an invalid common name, and an invalid certificate date.

## See also

[IXMLHTTPRequest3Callback](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nn-msxml6-ixmlhttprequest3callback)

[OnServerCertificateReceived](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest3callback-onservercertificatereceived)