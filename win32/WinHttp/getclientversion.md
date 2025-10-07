# getClientVersion function

Gets the version of the WPAD processing engine.

## Parameters

*IpAddressList*

A semi-colon delimited string containing IP addresses.

## Return value

A list of sorted semi-colon delimited IP addresses or an empty string if unable to sort the IP Address list.

## Remarks

Currently this function returns version 1.0.

Microsoft added this function to allow IT administrators to update their WPAD scripts to use different versions of the WPAD processing engine without causing breaks to their existing deployment. For example, if Microsoft added a function to the 2.0 version of the WPAD engine, then administrators can check the version before attempting to call that function. This allows their script to work with client running versions 1.0 and 2.0 of the WPAD engine.

## Examples

``` syntax
getClientVersion();
    returns the appropriate versions number of the WPAD engine.
```

## See also

[IPv6-Aware Proxy Helper API Definitions](https://learn.microsoft.com/windows/win32/winhttp/ipv6-aware-proxy-helper-api-definitions)

[IPv6 Extensions to Navigator Auto-Config File Format](https://learn.microsoft.com/windows/win32/winhttp/ipv6-extensions-to-navigator-auto-config-file-format)

