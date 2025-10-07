## Description

Contains the query parameters used in a call to [DnsServiceBrowse](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicebrowse).

## Members

### `Version`

The structure version must be either **DNS_QUERY_REQUEST_VERSION1** or **DNS_QUERY_REQUEST_VERSION2**. The value determines which of `pBrowseCallback` or `pBrowseCallbackV2` is active.

### `InterfaceIndex`

A value that contains the interface index over which the query is sent. If `InterfaceIndex` is 0, then all interfaces will be considered.

### `QueryName`

A pointer to a string that represents the service type whose matching services you wish to browse for. It takes the generalized form "\_\<ServiceType\>.\_\<TransportProtocol\>.local". For example, "_http._tcp.local", which defines a query to browse for http services on the local link.

### `pBrowseCallback`

A pointer to a function (of type [DNS_SERVICE_BROWSE_CALLBACK](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_service_browse_callback)) that represents the callback to be invoked asynchronously. This field is used if `Version` is **DNS_QUERY_REQUEST_VERSION1**.

### `pBrowseCallbackV2`

A pointer to a function (of type [DNS_QUERY_COMPLETION_ROUTINE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_query_completion_routine)) that represents the callback to be invoked asynchronously. This field is used if `Version` is **DNS_QUERY_REQUEST_VERSION2**.

### `pQueryContext`

A pointer to a user context.

## Remarks

## See also