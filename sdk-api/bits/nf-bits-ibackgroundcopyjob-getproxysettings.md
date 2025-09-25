# IBackgroundCopyJob::GetProxySettings

## Description

Retrieves the proxy information that the job uses to transfer the files.

## Parameters

### `pProxyUsage` [out]

Specifies the proxy settings the job uses to transfer the files. For a list of proxy options, see the
[BG_JOB_PROXY_USAGE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_proxy_usage) enumeration.

### `pProxyList` [out]

Null-terminated string that contains one or more proxies to use to transfer files. The list is space-delimited. For details on the format of the string, see the Listing Proxy Servers section of
[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality). Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppProxyList* when done.

### `pProxyBypassList` [out]

Null-terminated string that contains an optional list of host names or IP addresses, or both, that were not routed through the proxy. The list is space-delimited. For details on the format of the string, see the Listing the Proxy Bypass section of
[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality). Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppProxyBypassList* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Proxy information was successfully retrieved. |
| **E_INVALIDARG** | One or more of the parameters is **NULL**. |

## See also

[BG_JOB_PROXY_USAGE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_proxy_usage)

[IBackgroundCopyJob::SetProxySettings](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setproxysettings)