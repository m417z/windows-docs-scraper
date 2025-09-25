# FlsFree function

## Description

Releases a fiber local storage (FLS) index, making it available for reuse.

## Parameters

### `dwFlsIndex` [in]

The FLS index that was allocated by the
[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Freeing an FLS index frees the index for all instances of FLS in the current process. Freeing an FLS index also causes the associated callback routine to be called for each fiber, if the corresponding FLS slot contains a non-NULL value.

If the fibers of the process have allocated memory and stored a pointer to the memory in an FLS slot, they should free the memory before calling
**FlsFree**. The
**FlsFree** function does not free memory blocks whose addresses have been stored in the FLS slots associated with the FLS index. It is expected that DLLs call this function (if at all) only during DLL_PROCESS_DETACH.

## See also

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[FlsAlloc](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsalloc)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)