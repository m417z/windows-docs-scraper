# NetApiBufferFree function

## Description

The
**NetApiBufferFree** function frees the memory that the
[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function allocates. Applications should also call **NetApiBufferFree** to free the memory that other network management functions use internally to return information.

## Parameters

### `Buffer` [in]

A pointer to a buffer returned previously by another network management function or memory allocated by calling the [NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The
**NetApiBufferFree** function is used to free memory used by network management functions. This function is used in two cases:

* To free memory explicitly allocated by calls in an application to the [NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function when the memory is no longer needed.
* To free memory allocated internally by calls in an application to remotable network management functions that return information to the caller. The RPC run-time library internally allocates the buffer containing the return information.

Many network management functions retrieve information and return this information as a buffer that may contain a complex structure, an array of structures, or an array of nested structures. These functions use the RPC run-time library to internally allocate the buffer containing the return information, whether the call is to a local computer or a remote server. For example, the [NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum) function retrieves a lists of servers and returns this information as an array of structures pointed to by the *bufptr* parameter. When the function is successful, memory is allocated internally by the **NetServerEnum** function to store the array of structures returned in the *bufptr* parameter to the application. When this array of structures is no longer needed, the **NetApiBufferFree** function should be called by the application with the *Buffer* parameter set to the *bufptr* parameter returned by **NetServerEnum** to free this internal memory used. In these cases, the **NetApiBufferFree** function frees all of the internal memory allocated for the buffer including memory for nested structures, pointers to strings, and other data.

No special group membership is required to successfully execute the **NetApiBufferFree** function or any of the other [ApiBuffer functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions).

For a code sample that demonstrates how to use of the **NetApiBufferFree** function to free memory explicitly allocated by an application, see
the [NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate) function.

For a code sample that demonstrates how to use of the **NetApiBufferFree** function to free memory internally allocated by a network management function to return information, see
the [NetServerEnum](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserverenum) function.

## See also

[Api Buffer
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/apibuffer-functions)

[NetApiBufferAllocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferallocate)

[NetApiBufferReallocate](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferreallocate)

[NetApiBufferSize](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibuffersize)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths)

[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers)