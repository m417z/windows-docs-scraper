## Description

Used to asynchronously return the results of a service resolve operation.

## Parameters

### `Status`

A value that contains the status associated with this particular set of results.

### `pQueryContext`

A pointer to the user context that was passed to [DnsServiceResolve](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceresolve).

### `pInstance`

A pointer to a [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that contains detailed information about a service on the network. If not `nullptr`, then you are responsible for freeing the data using [DnsServiceFreeInstance](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicefreeinstance).

## Remarks

## See also