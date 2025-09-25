## Description

Used to copy a [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure.

## Parameters

### `pOrig`

A pointer to the [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that is to be copied.

## Return value

A pointer to a newly allocated [DNS_SERVICE_INSTANCE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_instance) structure that's a copy of `pOrig`. Your application is responsible for freeing the associated memory by calling [DnsServiceFreeInstance](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicefreeinstance).

## Remarks

## See also