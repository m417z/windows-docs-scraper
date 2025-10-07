# WinHttpRequestOption enumeration

The **WinHttpRequestOption** enumeration includes options that can be set or retrieved for the current Microsoft Windows HTTP Services (WinHTTP) session.

## Constants

**WinHttpRequestOption\_UserAgentString**

Sets or retrieves a **VARIANT** that contains the [*user agent*](https://learn.microsoft.com/windows/win32/winhttp/glossary) string.

**WinHttpRequestOption\_URL**

Retrieves a **VARIANT** that contains the URL of the resource. This value is read-only; you cannot set the URL using this property. The URL cannot be read until the [**Open**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-open) method is called. This option is useful for checking the URL after the [**Send**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-send) method is finished to verify that any redirection occurred.

**WinHttpRequestOption\_URLCodePage**

Sets or retrieves a **VARIANT** that identifies the [*code page*](https://learn.microsoft.com/windows/win32/winhttp/glossary) for the URL string. The default value is the UTF-8 code page. The code page is used to convert the Unicode URL string, passed in the [**Open**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-open) method, to a single-byte string representation.

**WinHttpRequestOption\_EscapePercentInURL**

Sets or retrieves a **VARIANT** that indicates whether percent characters in the URL string are converted to an escape sequence. The default value of this option is **VARIANT\_TRUE** which specifies all unsafe American National Standards Institute (ANSI) characters except the percent symbol are converted to an escape sequence.

**WinHttpRequestOption\_SslErrorIgnoreFlags**

Sets or retrieves a **VARIANT** that indicates which server certificate errors should be ignored. This can be a combination of one or more of the following flags.

| Error | Value |
|--------------------------------------------------------|--------|
| Unknown certification authority (CA) or untrusted root | 0x0100 |
| Wrong usage | 0x0200 |
| Invalid common name (CN) | 0x1000 |
| Invalid date or certificate expired | 0x2000 |

The default value of this option in Version 5.1 of WinHTTP is zero, which results in no errors being ignored. In earlier versions of WinHTTP, the default setting was 0x3300, which resulted in all server certificate errors being ignored by default.

**WinHttpRequestOption\_SelectCertificate**

Sets a **VARIANT** that specifies the client certificate that is sent to a server for authentication. This option indicates the location, [*certificate store*](https://learn.microsoft.com/windows/win32/winhttp/glossary), and subject of a client certificate delimited with backslashes. For more information about selecting a client certificate, see [SSL in WinHTTP](https://learn.microsoft.com/windows/win32/winhttp/ssl-in-winhttp).

**WinHttpRequestOption\_EnableRedirects**

Sets or retrieves a **VARIANT** that indicates whether requests are automatically redirected when the server specifies a new location for the resource. The default value of this option is **VARIANT\_TRUE** to indicate that requests are automatically redirected.

**WinHttpRequestOption\_UrlEscapeDisable**

Sets or retrieves a **VARIANT** that indicates whether unsafe characters in the path and query components of a URL are converted to escape sequences. The default value of this option is **VARIANT\_TRUE**, which specifies that characters in the path and query are converted.

**WinHttpRequestOption\_UrlEscapeDisableQuery**

Sets or retrieves a **VARIANT** that indicates whether unsafe characters in the query component of the URL are converted to escape sequences. The default value of this option is **VARIANT\_TRUE**, which specifies that characters in the query are converted.

**WinHttpRequestOption\_SecureProtocols**

Sets or retrieves a **VARIANT** that indicates which secure protocols can be used. This option selects the protocols acceptable to the client. The protocol is negotiated during the Secure Sockets Layer (SSL) handshake. This can be a combination of one or more of the following flags.

| Protocol | Value |
|------------------------------------|--------|
| SSL 2.0 | 0x0008 |
| SSL 3.0 | 0x0020 |
| Transport Layer Security (TLS) 1.0 | 0x0080 |

The default value of this option is 0x0028, which indicates that SSL 2.0 or SSL 3.0 can be used. If this option is set to zero, the client and server are not able to determine an acceptable security protocol and the next [**Send**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-send) results in an error.

**WinHttpRequestOption\_EnableTracing**

Sets or retrieves a **VARIANT** that indicates whether tracing is currently enabled. Also see [Collect WinHTTP traces](https://learn.microsoft.com/windows/win32/winhttp/collect-traces).

**WinHttpRequestOption\_RevertImpersonationOverSsl**

Controls whether the [**WinHttpRequest**](https://learn.microsoft.com/windows/win32/winhttp/winhttprequest) object temporarily reverts client impersonation for the duration of the SSL certificate authentication operations. The default setting for the **WinHttpRequest** object is **TRUE**. Set this option to **FALSE** to keep impersonation while performing certificate authentication operations.

**WinHttpRequestOption\_EnableHttpsToHttpRedirects**

Controls whether or not WinHTTP allows redirects. By default, all redirects are automatically followed, except those that transfer from a secure (https) URL to a non-secure (http) URL. Set this option to **TRUE** to enable HTTPS to HTTP redirects.

**WinHttpRequestOption\_EnablePassportAuthentication**

Enables or disables support for Passport authentication. By default, automatic support for Passport authentication is disabled; set this option to **TRUE** to enable Passport authentication support.

**WinHttpRequestOption\_MaxAutomaticRedirects**

Sets or retrieves the maximum number of redirects that WinHTTP follows; the default is 10. This limit prevents unauthorized sites from making the WinHTTP client stall following a large number of redirects.

**Windows XP with SP1 and Windows 2000 with SP3:** This enumeration value is not supported.

**WinHttpRequestOption\_MaxResponseHeaderSize**

Sets or retrieves a bound set on the maximum size of the header portion of the server's response. This bound protects the client from a malicious server attempting to stall the client by sending a response with an infinite amount of header data. The default value is 64 KB.

**Windows XP with SP1 and Windows 2000 with SP3:** This enumeration value is not supported.

**WinHttpRequestOption\_MaxResponseDrainSize**

Sets or retrieves a bound on the amount of data that will be drained from responses in order to reuse a connection. The default is 1 MB.

**Windows XP with SP1 and Windows 2000 with SP3:** This enumeration value is not supported.

**WinHttpRequestOption\_EnableHttp1\_1**

Sets or retrieves a boolean value that indicates whether HTTP/1.1 or HTTP/1.0 should be used. The default is **TRUE**, so that HTTP/1.1 is used by default.

**Windows XP with SP1 and Windows 2000 with SP3:** This enumeration value is not supported.

**WinHttpRequestOption\_EnableCertificateRevocationCheck**

Enables server certificate revocation checking during SSL negotiation. When the server presents a certificate, a check is performed to determine whether the certificate has been revoked by its issuer. If the certificate is indeed revoked, or the revocation check fails because the Certificate Revocation List (CRL) cannot be downloaded, the request fails; such revocation errors cannot be suppressed.

**Windows XP with SP1 and Windows 2000 with SP3:** This enumeration value is not supported.

## Remarks

Set an option by specifying one of the preceding constants as the parameter of the [**Option**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-option) property.

> [!Note]
> For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/win32/winhttp/winhttp-start-page) section of the WinHttp start page.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP, Windows 2000 Professional with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003, Windows 2000 Server with SP3 \[desktop apps only\]<br> |
| Redistributable<br> | WinHTTP 5.0 and Internet Explorer 5.01 or later on Windows XP and Windows 2000.<br> |
| IDL<br> | HttpRequest.idl |

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/win32/winhttp/winhttp-versions)

