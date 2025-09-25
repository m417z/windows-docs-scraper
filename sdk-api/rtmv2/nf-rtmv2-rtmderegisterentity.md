# RtmDeregisterEntity function

## Description

The
**RtmDeregisterEntity** function unregisters a client from a routing table manager instance and address family.

## Parameters

### `RtmRegHandle` [in]

Handle to the client obtained from a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The handle is invalid. |

## Remarks

Before calling this function, the client must ensure that all locks, handles, and information structures are released with the appropriate functions.

When the client calls
**RtmDeregisterEntity**, the handle that was returned by a previous call to
[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity) is released. The client must not call any RTMv2 functions after releasing this handle.

If the client does call any functions that access the routing table manager after the client has unregistered, the client's process may be terminated.

## See also

[RtmRegisterEntity](https://learn.microsoft.com/windows/desktop/api/rtmv2/nf-rtmv2-rtmregisterentity)