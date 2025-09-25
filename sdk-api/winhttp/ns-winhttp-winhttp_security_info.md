## Description

The **WINHTTP_SECURITY_INFO** structure contains the SChannel connection and cipher information for a request.

## Members

### `ConnectionInfo`

[**SecPkgContext_ConnectionInfo**](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_connectioninfo) containing the SChannel connection information for the request.

### `CipherInfo`

[**SecPkgContext_CipherInfo**](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_cipherinfo) containing the SChannel cipher information for the request.

## Remarks

This structure is used with [**WinHttpQueryOption**](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption) to retrieve security information for a request by specifying the **WINHTTP_OPTION_SECURITY_INFO** flag.

## See also

[WinHttpQueryOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpqueryoption)