# WSManProxyAccessType enumeration

## Description

Defines the proxy access type.

## Constants

### `WSMAN_OPTION_PROXY_IE_PROXY_CONFIG:1`

Use the Internet Explorer proxy configuration for the current user. This is the default setting.

### `WSMAN_OPTION_PROXY_WINHTTP_PROXY_CONFIG:2`

Use the proxy settings configured for WinHTTP.

### `WSMAN_OPTION_PROXY_AUTO_DETECT:4`

Force autodetection of a proxy.

### `WSMAN_OPTION_PROXY_NO_PROXY_SERVER:8`

Do not use a proxy server. All host names are resolved locally.

## Remarks

The **WSMAN_OPTION_PROXY_IE_PROXY_CONFIG** option returns the current user Internet Explorer proxy settings for the current active network connection. This option requires the user profile to be loaded. This option can be directly used when called within a process that is running under an interactive user account identity. If the client application is running under a user context that is different than the interactive user, the client application must explicitly load the user profile prior to using this option.

If the Windows Remote Management API is called from a service, **WSMAN_OPTION_PROXY_WINHTTP_PROXY_CONFIG** or **WSMAN_OPTION_PROXY_AUTO_DETECT** should be used if a proxy is required.

The **WSMAN_OPTION_PROXY_WINHTTP_PROXY_CONFIG** option translates into the **WINHTTP_ACCESS_TYPE_DEFAULT_PROXY** option in WinHTTP. WinHTTP retrieves the static proxy or direct configuration from the registry. **WINHTTP_ACCESS_TYPE_DEFAULT_PROXY** does not inherit browser proxy settings. WinHTTP does not share any proxy settings with Internet Explorer. This option gets the WinHTTP proxy configuration set by the ProxyCfg.exe utility.