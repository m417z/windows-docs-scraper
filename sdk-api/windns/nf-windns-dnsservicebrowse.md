## Description

Used to initiate a DNS-SD discovery for services running on the local network.

## Parameters

### `pRequest`

A pointer to a [DNS_SERVICE_BROWSE_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_browse_request) structure that contains the browse request information.

### `pCancel`

A pointer to a [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that can be used to cancel a pending asynchronous browsing operation. This handle must remain valid until the query is canceled.

## Return value

If successful, returns **DNS_REQUEST_PENDING**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is asynchronous. As services are being discovered, the browse callback will be invoked for each result.

## See also