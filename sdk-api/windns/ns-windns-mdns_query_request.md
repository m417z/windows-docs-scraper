## Description

Contains the necessary information to perform an mDNS query.

## Members

### `Version`

The structure version must be **DNS_QUERY_REQUEST_VERSION1**.

### `ulRefCount`

Reserved. Do not use.

### `Query`

A string representing the name to be queried over mDNS.

### `QueryType`

A value representing the type of the records to be queried. See [DNS_RECORD_TYPE](https://learn.microsoft.com/openspecs/windows_protocols/ms-dnsp/39b03b89-2264-4063-8198-d62f62a6441a) for possible values.

### `QueryOptions`

A value representing the query options. **DNS_QUERY_STANDARD** is the only supported value.

### `InterfaceIndex`

A value that contains the interface index over which the service is to be advertised. If `InterfaceIndex` is 0, then all interfaces will be considered.

### `pQueryCallback`

A pointer to a function (of type [MDNS_QUERY_CALLBACK](https://learn.microsoft.com/windows/win32/api/windns/nc-windns-mdns_query_callback)) that represents the callback to be invoked asynchronously whenever mDNS results are available.

### `pQueryContext`

A pointer to a user context.

### `fAnswerReceived`

Reserved. Do not use.

### `ulResendCount`

Reserved. Do not use.

## Remarks

## See also