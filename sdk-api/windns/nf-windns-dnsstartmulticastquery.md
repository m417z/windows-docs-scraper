## Description

Used to register a discoverable service on this device.

## Parameters

### `pQueryRequest`

A pointer to an [MDNS_QUERY_REQUEST](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-mdns_query_request) structure that contains information about the query to be performed.

### `pHandle`

A pointer to an [MDNS_QUERY_HANDLE](https://learn.microsoft.com/windows/win32/api/windns/ns-windns-mdns_query_handle) structure that will be populated with the necessary data. This structure is to be passed later to [DnsStopMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstopmulticastquery) to stop the query.

## Return value

If successful, returns **ERROR_SUCCESS**; otherwise, returns the appropriate DNS-specific error code as defined in `Winerror.h`. For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is asynchronous. The query runs indefinitely, until [DnsStopMulticastQuery](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsstopmulticastquery) is called. For each response from the network, the query callback will be invoked with the appropriate status and results.

## See also