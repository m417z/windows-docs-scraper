# DNS_PROXY_INFORMATION_TYPE enumeration

## Description

The
**DNS_PROXY_INFORMATION_TYPE** enumeration defines the proxy information type in the [DNS_PROXY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_proxy_information) structure.

## Constants

### `DNS_PROXY_INFORMATION_DIRECT`

The type is bypass proxy information.

### `DNS_PROXY_INFORMATION_DEFAULT_SETTINGS`

The type is the user's default browser proxy settings.

### `DNS_PROXY_INFORMATION_PROXY_NAME`

The type is defined by the **proxyName** member of the [DNS_PROXY_INFORMATION](https://learn.microsoft.com/windows/desktop/api/windns/ns-windns-dns_proxy_information) structure.

### `DNS_PROXY_INFORMATION_DOES_NOT_EXIST`

The type does not exist. DNS policy does not have proxy information for this name space. This type is used if no wildcard policy exists and there is no default proxy information.

## See also

[DNS Enumerations](https://learn.microsoft.com/windows/desktop/DNS/dns-enumerations)