## Description

Used to notify your application that service registration has completed.

## Parameters

### `Status`

A value that contains the status of the registration.

### `pQueryContext`

A pointer to the user context that was passed to [DnsServiceRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceregister).

### `pInstance`

A pointer to a [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that describes the service that was registered. If not `nullptr`, then you are responsible for freeing the data using [DnsServiceFreeInstance](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicefreeinstance).

## Remarks

## See also