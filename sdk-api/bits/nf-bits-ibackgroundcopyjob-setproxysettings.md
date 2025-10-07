# IBackgroundCopyJob::SetProxySettings

## Description

Specifies which proxy to use to transfer files.

## Parameters

### `ProxyUsage` [in]

Specifies whether to use the user's proxy settings, not to use a proxy, or to use application-specified proxy settings. The default is to use the user's proxy settings, **BG_JOB_PROXY_USAGE_PRECONFIG**. For a list of proxy options, see the
[BG_JOB_PROXY_USAGE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_proxy_usage) enumeration.

### `ProxyList` [in]

Null-terminated string that contains the proxies to use to transfer files. The list is space-delimited. For details on specifying a proxy, see Remarks.

 This parameter must be **NULL** if the value of *ProxyUsage* is **BG_JOB_PROXY_USAGE_PRECONFIG**, **BG_JOB_PROXY_USAGE_NO_PROXY**, or **BG_JOB_PROXY_USAGE_AUTODETECT**.

The length of the proxy list is limited to 4,000 characters, not including the null terminator.

### `ProxyBypassList` [in]

Null-terminated string that contains an optional list of host names, IP addresses, or both, that can bypass the proxy. The list is space-delimited. For details on specifying a bypass proxy, see Remarks.

This parameter must be **NULL** if the value of *ProxyUsage* is **BG_JOB_PROXY_USAGE_PRECONFIG**, **BG_JOB_PROXY_USAGE_NO_PROXY**, or **BG_JOB_PROXY_USAGE_AUTODETECT**.

The length of the proxy bypass list is limited to 4,000 characters, not including the null terminator.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Proxy was successfully specified. |
| **E_NOTIMPL** | The value for *ProxyUsage* is not defined in the [BG_JOB_PROXY_USAGE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_proxy_usage) enumeration. |
| **BG_E_PROXY_LIST_TOO_LARGE** | The *pProxyList* buffer cannot exceed 32 KB. |
| **BG_E_PROXY_BYPASS_LIST_TOO_LARGE** | The *pProxyBypassList* cannot exceed 32 KB. |
| **BG_E_INVALID_STATE** | The state of the job cannot be **BG_JOB_STATE_CANCELLED** or **BG_JOB_STATE_ACKNOWLEDGED**. |
| **E_INVALIDARG** | The *pProxyList* parameter cannot be **NULL** if *ProxyUsage* is **BG_JOB_PROXY_USAGE_OVERRIDE**. |

## Remarks

The proxy information you provide is validated at run time. If the proxy information is invalid, the job enters the **BG_JOB_STATE_ERROR** state with a **BG_E_INVALID_PROXY_INFO** error code.

 If your service runs as LocalSystem, you should use the **SetProxySettings** method to explicitly specify a proxy or proxy bypass list for the account and set *ProxyUsage* to **BG_JOB_PROXY_USAGE_OVERRIDE**. For more information on using system accounts with BITS, see [Service Accounts and BITS](https://learn.microsoft.com/windows/desktop/Bits/service-accounts-and-bits).

BITS does not recognize the proxy settings that are set using the Proxycfg.exe file.

Specify a proxy as:

"[*protocol*=][*protocol*"://"]*server*[":"*port*]"

The valid protocols are HTTP and HTTPS. The proxy list can contain the port number that is used to access the proxy. For example, to list an HTTP proxy, a valid string is "http=http://*http_proxy_name*:80", where *http_proxy_name* is the name of the proxy server and 80 is the port number that you must use to access the proxy. If the proxy uses the default port number for that protocol, then you can omit the port number. If a proxy name is listed by itself, you can use it as the default proxy for any protocols that do not have a specified proxy. For example, "http=http://*http_proxy**other_proxy*" uses *http_proxy* for any HTTP operations, while the HTTPS protocol uses the proxy named *other_proxy*.

You can list locally known host names or Internet Protocol (IP) addresses in the proxy bypass list. This name can contain wildcards, such as "*", that cause the application to bypass the proxy server for addresses that fit the specified pattern, for example, "*.microsoft.com" or "*.org". Wildcard characters must be the left-most characters in the name. For example, "aaa.*" is not supported. You can specify the \<local> macro to indicate that all local intranet sites are bypassed. Local intranet sites are considered to be all servers that do not contain a period in their name.

BITS uses the Internet Explorer proxy settings of the user if an application does not specify a proxy usage. This default behavior typically works if the application submits the job in the context of an interactive user but may not work if a service running as LocalSystem submits the job. You can specify Internet Explorer proxy settings for LocalSystem; however, it is difficult to detect these settings when problems occur.

## See also

[BG_JOB_PROXY_USAGE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_proxy_usage)

[IBackgroundCopyJob::GetProxySettings](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getproxysettings)