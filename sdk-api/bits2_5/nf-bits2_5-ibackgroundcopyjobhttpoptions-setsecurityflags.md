# IBackgroundCopyJobHttpOptions::SetSecurityFlags

## Description

Sets flags for HTTP that determine whether the certificate revocation list is checked and certain certificate errors are ignored, and the policy to use when a server redirects the HTTP request.

## Parameters

### `Flags` [in]

HTTP security flags that indicate which errors to ignore when connecting to the server. You can set one or more of the following flags:

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
| **BG_HTTP_REDIRECT_POLICY_MASK**<br><br>0x0700 | Bitmask that you can use with the security flag value to determine which redirect policy is in effect. It does not include the flag ALLOW_HTTPS_TO_HTTP. |
| **BG_HTTP_REDIRECT_POLICY_ALLOW_HTTPS_TO_HTTP**<br><br>0x0800 | Allows the server to redirect an HTTPS request to an HTTP URL.<br><br>You can combine this flag with BG_HTTP_REDIRECT_POLICY_ALLOW_SILENT and BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT. |

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the headers. |
| ****E_NOTIMPL**** | The flag value is not supported. |

## Remarks

If CRL checking is requested, BITS performs the check for all files in the job that specify the HTTPS protocol. The check is made for each file before the file begins transferring. If you set this value to **TRUE** after BITS has partially downloaded a file, BITS will reschedule the job and begin downloading the file again. Files that are already downloaded are not affected.

BITS uses the CRL on the local computer if the CRL is up-to-date; otherwise, BITS downloads the CRL from the certification authority (CA) that signed the certificate.

The job goes into the fatal error state if the following errors occur.

| Error code | Description |
| --- | --- |
| **ERROR_WINHTTP_SECURE_CERT_REV_FAILED** | Unable to request CRL checking because the certificate server is offline or the CRL cannot be downloaded. |
| **ERROR_WINHTTP_SECURE_CERT_REVOKED** | The certificate is revoked. |

The redirect policy applies to all files in a download job (the policy does not apply to upload jobs).

**Prior to BITS 3.0:** The redirect policies are not supported.

If the policy is BG_HTTP_REDIRECT_POLICY_DISALLOW and the server redirects your request, the job is placed in the fatal error state with one of the following error codes. For descriptions of the error codes, see [HTTP Status Codes](https://learn.microsoft.com/windows/desktop/WinHttp/http-status-codes).

* HRESULT_FROM_WIN32(HTTP_STATUS_AMBIGUOUS)
* HRESULT_FROM_WIN32(HTTP_STATUS_MOVED)
* HRESULT_FROM_WIN32(HTTP_STATUS_REDIRECT)
* HRESULT_FROM_WIN32(HTTP_STATUS_REDIRECT_METHOD)
* HRESULT_FROM_WIN32(HTTP_STATUS_REDIRECT_KEEP_VERB)

BITS does not support redirection from HTTP or HTTPs to SMB.

If peer caching is enabled and you specify BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT, the file is stored in the cache with the final redirected URL. If a peer then tries to download the file with the original URL, the peer will not find the file in the peer's cache and will end up downloading the file from the origin server.

If you specify and the file is downloaded from the

Note that setting BG_HTTP_REDIRECT_POLICY_ALLOW_REPORT may affect the result when calling the [IBackgroundCopyJob3::ReplaceRemotePrefix](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-replaceremoteprefix) method. If a server redirected your request, BITS will have already changed the original URL to the final redirected URL, so calling the **ReplaceRemotePrefix** method will not find files with the original URL.

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::GetSecurityFlags](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getsecurityflags)