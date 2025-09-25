## Description

Used to obtain more information about a service advertised on the local network.

## Parameters

### `pRequest`

A pointer to a [DNS_SERVICE_RESOLVE_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_resolve_request) structure that contains the resolve request information.

### `pCancel`

A pointer to a [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that can be used to cancel a pending asynchronous resolve operation. This handle must remain valid until the query is canceled.

## Return value

If successful, returns **DNS_REQUEST_PENDING**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is asynchronous. Upon completion, the resolve callback will be invoked for each result. In contrast to [DnsServiceBrowse](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicebrowse)—which returns the service name as a minimum—**DnsServiceResolve** can be used to retrieve additional information, such as hostname, IP address, and TEXT records.

## See also