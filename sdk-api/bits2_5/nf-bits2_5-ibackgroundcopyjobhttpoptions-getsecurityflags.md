# IBackgroundCopyJobHttpOptions::GetSecurityFlags

## Description

Retrieves the flags for HTTP that determine whether the certificate revocation list is checked and certain certificate errors are ignored, and the policy to use when a server redirects the HTTP request.

## Parameters

### `pFlags` [out]

HTTP security flags that indicate which errors to ignore when connecting to the server. One or more of the following flags can be set:

| Value | Meaning |
| --- | --- |
| **BG_SSL_ENABLE_CRL_CHECK**<br><br>0x0001 | Check the certificate revocation list (CRL) to verify that the server certificate has not been revoked. |
| **BG_SSL_IGNORE_CERT_CN_INVALID**<br><br>0x0002 | Ignores errors caused when the certificate host name of the server does not match the host name in the request. |
| **BG_SSL_IGNORE_CERT_DATE_INVALID**<br><br>0x0004 | Ignores errors caused by an expired certificate. |
| **BG_SSL_IGNORE_UNKNOWN_CA**<br><br>0x0008 | Ignore errors associated with an unknown certification authority (CA). |
| **BG_SSL_IGNORE_CERT_WRONG_USAGE**<br><br>0x0010 | Ignore errors associated with the use of a certificate. |
| **BG_HTTP_REDIRECT_POLICY_ALLOW_SILENT**<br><br>0x0000 | Allows the server to redirect your request to another server. This is the default. |
| **BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT**<br><br>0x0100 | Allows the server to redirect your request to another server. BITS updates the remote name with the final URL. |
| **BG_HTTP_REDIRECT_POLICY_DISALLOW**<br><br>0x0200 | Places the job in the fatal error state when the server redirects your request to another server. BITS updates the remote name with the redirected URL. |
| **BG_HTTP_REDIRECT_POLICY_MASK**<br><br>0x0700 | Bitmask that you can use with the security flag value to determine which redirect policy is in effect. It does not include the flag ALLOW_HTTPS_TO_HTTP.<br><br>The following example shows how to use this mask to test for the BG_HTTP_REDIRECT_POLICY_DISALLOW redirection policy.<br><br>`if (BG_HTTP_REDIRECT_POLICY_DISALLOW == (flags & BG_HTTP_REDIRECT_POLICY_MASK))` |
| **BG_HTTP_REDIRECT_POLICY_ALLOW_HTTPS_TO_HTTP**<br><br>0x0800 | Allows the server to redirect an HTTPS request to an HTTP URL.<br><br>You can combine this flag with BG_HTTP_REDIRECT_POLICY_ALLOW_SILENT and BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT. |

## Return value

Returns S_OK when successful.

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::SetSecurityFlags](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setsecurityflags)