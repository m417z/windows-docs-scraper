## Description

Used to stop a running [DnsStartMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstartmulticastquery) operation.

## Parameters

### `pHandle`

A pointer to the [MDNS_QUERY_HANDLE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-mdns_query_handle) structure that was passed to the [DnsStartMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstartmulticastquery) call that is to be stopped.

## Return value

If successful, returns **ERROR_SUCCESS**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also