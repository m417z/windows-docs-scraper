## Description

Contains the query parameters used in a call to [DnsServiceResolve](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceresolve). Use that function, and this structure, after you've found a specific service name that you'd like to connect to.

## Members

### `Version`

The structure version must be **DNS_QUERY_REQUEST_VERSION1**.

### `InterfaceIndex`

A value that contains the interface index over which the query is sent. If `InterfaceIndex` is 0, then all interfaces will be considered.

### `QueryName`

A pointer to a string that represents the service name. This is a fully qualified domain name that begins with a service name, and ends with ".local". It takes the generalized form "\<ServiceName\>.\_\<ServiceType\>.\_\<TransportProtocol\>.local". For example, "MyMusicServer._http._tcp.local".

### `pResolveCompletionCallback`

A pointer to a function (of type [DNS_SERVICE_RESOLVE_COMPLETE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_service_resolve_complete)) that represents the callback to be invoked asynchronously.

### `pQueryContext`

A pointer to a user context.

## Remarks

## See also