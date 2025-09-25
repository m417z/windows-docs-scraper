# AllJoynReceiveFromBus function

## Description

Receives data from the bus via named pipe.

## Parameters

### `connectedBusHandle` [in]

Pipe handle.

### `buffer` [out]

Output data buffer.

### `bytesToRead` [in]

Number of bytes to receive.

### `bytesTransferred` [out, optional]

Number of bytes read.

### `reserved` [in, out]

May be used in a future version as OVERLAPPED address. Currently must be NULL.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).