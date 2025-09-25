# XHR_AUTH enumeration

## Description

Specifies whether to allow authentication to be used to connect to a proxy or to connect to the HTTP server.

## Constants

### `XHR_AUTH_ALL:0`

Allow authentication to both proxy and server.

### `XHR_AUTH_NONE:0x1`

Disable authentication to both the proxy and server.

### `XHR_AUTH_PROXY:0x2`

Enable authentication to the proxy and disable auth to the server.

## See also

[SetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/msxml6/nf-msxml6-ixmlhttprequest2-setproperty)