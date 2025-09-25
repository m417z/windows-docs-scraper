# NetApiBufferReallocate function

## Description

The
**NetApiBufferReallocate** function changes the size of a buffer allocated by a previous call to the
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

## Parameters

### `OldBuffer` [in]

Pointer to the buffer returned by a call to the
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

### `NewByteCount` [in]

Specifies the new size of the buffer, in bytes.

### `NewBuffer` [out]

Receives the pointer to the reallocated buffer.

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