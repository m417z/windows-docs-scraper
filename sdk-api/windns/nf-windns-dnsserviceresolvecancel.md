## Description

Used to cancel a running DNS-SD resolve query.

## Parameters

### `pCancelHandle`

A pointer to the [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that was passed to the [DnsServiceResolve](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsserviceresolve) call that is to be cancelled.

## Return value

If successful, returns **ERROR_SUCCESS**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also