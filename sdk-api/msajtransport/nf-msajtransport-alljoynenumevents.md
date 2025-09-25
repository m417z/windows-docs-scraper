# AllJoynEnumEvents function

## Description

Provides AllJoyn transport functionality similar to the TCP socket [WSAEnumNetworkEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumnetworkevents) functionality.

## Parameters

### `connectedBusHandle` [in]

Pipe handle.

### `eventToReset` [in, optional]

Optional handle to the event to be reset after completion of this call.

### `eventTypes` [out]

Output for bitmask of events being set.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).