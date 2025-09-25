# NetApiBufferSize function

## Description

The
**NetApiBufferSize** function returns the size, in bytes, of a buffer allocated by a call to the
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

## Parameters

### `Buffer` [in]

Pointer to a buffer returned by the
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

### `ByteCount` [out]

Receives the size of the buffer, in bytes.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to successfully execute the ApiBuffer functions.

For a code sample that demonstrates how to use the network management
[ApiBuffer functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions), see
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate).

## See also

[Api Buffer
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions)

[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)