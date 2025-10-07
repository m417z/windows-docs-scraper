# isResolvableEx function

Determines if a given host string can resolve to an IP address.

## Parameters

*host*

A string containing the HTTP host that is supplied to FindProxyForUrl.

## Return value

TRUE if the host is resolvable to a IPv4 or IPv6 address; otherwise, FALSE.

## Examples

``` syntax
isResolvableEx(host);
    true if the hostname can be resolved to and IP address
```

``` syntax
isResolvableEx(host);
    false if the hostname cannot be resolved to an IP address
```

## See also

[IPv6-Aware Proxy Helper API Definitions](https://learn.microsoft.com/windows/win32/winhttp/ipv6-aware-proxy-helper-api-definitions)

[IPv6 Extensions to Navigator Auto-Config File Format](https://learn.microsoft.com/windows/win32/winhttp/ipv6-extensions-to-navigator-auto-config-file-format)

