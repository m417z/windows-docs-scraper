## Description

Used to cancel a running DNS-SD discovery query.

## Parameters

### `pCancelHandle`

A pointer to the [DNS_SERVICE_CANCEL](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-dns_service_cancel) structure that was passed to the [DnsServiceBrowse](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsservicebrowse) call that is to be cancelled.

## Return value

If successful, returns **ERROR_SUCCESS**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Canceling the query causes one further invocation of the browse callback, with status **ERROR_CANCELLED**.

## See also