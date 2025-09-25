# AllJoynSendToBus function

## Description

Sends data to the bus via named pipe. The caller of this API is responsible to check if the *bytesTransferred* is less than the
requested bytes and call this API again to resend the rest of the data.

When the named pipe *outBufferSize* is less than the *bytesToWrite*, writing to named pipe is returning TRUE and *bytesTransferred == 0*, rather than returning TRUE
and transferring as much as possible.

## Parameters

### `connectedBusHandle` [in]

Pipe handle.

### `buffer` [in]

Input data buffer.

### `bytesToWrite` [in]

Number of bytes to send.

### `bytesTransferred` [out, optional]

Number of bytes written.

### `reserved` [in, out]

May be used in a future version as OVERLAPPED address. Currently must be NULL.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).