# AllJoynEventSelect function

## Description

Provides AllJoyn transport functionality similar to the TCP socket [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) functionality.

## Parameters

### `connectedBusHandle` [in]

Pipe handle.

### `eventHandle` [in]

Handle to the event to be set when any of the events in bit mask happens.

### `eventTypes` [in]

Bit mask of events to select.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).