# sortIpAddressList function

Sorts a list of IP addresses.

## Parameters

*IpAddressList*

A semi-colon delimited string containing IP addresses.

## Return value

A list of sorted semi-colon delimited IP addresses or an empty string if unable to sort the IP Address list.

## Remarks

FindProxyforURLEx implementers should add code that breaks the string of semi-colon delimited IP addresses into separate addresses.

## Examples

``` syntax
sortIpAddressList(2001:4898:28:3:201:2ff:feea:fc14;
                  157.59.139.22;
                  fe80::5efe:157.59.139.22");
    returns "fe80::5efe:157.59.139.22;2001:4898:28:3:201:2ff:feea:fc14;157.59.139.22"
    A list of sorted IP addresses. If there both IPv6 and IPv4 IP addresses are passed as input to this function, then the sorted IPv6 addresses are followed by sorted IPv4 addresses
```

## See also

[IPv6-Aware Proxy Helper API Definitions](https://learn.microsoft.com/windows/win32/winhttp/ipv6-aware-proxy-helper-api-definitions)

[IPv6 Extensions to Navigator Auto-Config File Format](https://learn.microsoft.com/windows/win32/winhttp/ipv6-extensions-to-navigator-auto-config-file-format)

