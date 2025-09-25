## Description

Contains the information necessary to advertise a service using [DnsServiceRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceregister), or to stop advertising it using [DnsServiceDeRegister](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicederegister).

## Members

### `Version`

The structure version must be **DNS_QUERY_REQUEST_VERSION1**.

### `InterfaceIndex`

A value that contains the interface index over which the service is to be advertised. If `InterfaceIndex` is 0, then all interfaces will be considered.

### `pServiceInstance`

A pointer to a [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that describes the service to be registered.

### `pRegisterCompletionCallback`

A pointer to a function (of type [DNS_SERVICE_REGISTER_COMPLETE](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-dns_service_register_complete)) that represents the callback to be invoked asynchronously.

### `pQueryContext`

A pointer to a user context.

### `hCredentials`

Not used.

### `unicastEnabled`

`true` if the DNS protocol should be used to advertise the service; `false` if the mDNS protocol should be used.

## Remarks

## See also