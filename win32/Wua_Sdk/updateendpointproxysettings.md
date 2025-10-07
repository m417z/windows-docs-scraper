# UpdateEndpointProxySettings structure

The **UpdateEndpointProxySettings** structure defines the proxy settings used when requesting a token.

## Members

**szProxyAddr**

The DNS name or IP address of the proxy server to use (for example, "proxy.somecorp.com" or "192.168.0.4"), or an empty string if no proxy should be used.

**szBypassList**

A list of host addresses that should bypass the proxy server, or an empty string if all host addresses should use the proxy server

WUA does not use this data if **szProxyAddr** is empty.

**szUserName**

The username that is used to authenticate with the proxy server, or the empty string if no authentication is needed.

WUA does not use this data if **szProxyAddr** is empty.

**szPassword**

The password that is used to authenticate with the proxy server, or the empty string if no authentication is needed.

WUA does not use this data if **szProxyAddr** is empty.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | UpdateEndpointAuth.h |
| IDL<br> | UpdateEndpointAuth.idl |

## See also

[**GetEndpointToken**](https://learn.microsoft.com/windows/win32/wua_sdk/iupdateendpointauthprovider-getendpointtoken)

