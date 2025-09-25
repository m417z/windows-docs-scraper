# PREAD_PROCESS_MEMORY_ROUTINE64 callback function

## Description

An application-defined callback function used with the
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function. It is called when
**StackWalk64** needs to read memory from the address space of the process.

The **PREAD_PROCESS_MEMORY_ROUTINE64** type defines a pointer to this callback function.
**ReadProcessMemoryProc64** is a placeholder for the application-defined function name.

## Parameters

### `hProcess` [in]

A handle to the process for which the stack trace is generated.

### `qwBaseAddress` [in]

The base address of the memory to be read.

### `lpBuffer` [out]

A pointer to a buffer that receives the memory to be read.

### `nSize` [in]

The size of the memory to be read, in bytes.

### `lpNumberOfBytesRead` [out]

A pointer to a variable that receives the number of bytes actually read.

## Return value

If the function succeeds, the return value should be **TRUE**. If the function fails, the return value should be **FALSE**.

## Remarks

In many cases, this function can best service the callback with a corresponding call to [ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory).

This function should read as much of the requested memory as possible. The
[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk) function handles the case where only part of the requested memory is read.

This callback function supersedes the *PREAD_PROCESS_MEMORY_ROUTINE* callback function. *PREAD_PROCESS_MEMORY_ROUTINE* is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define PREAD_PROCESS_MEMORY_ROUTINE PREAD_PROCESS_MEMORY_ROUTINE64
#else
typedef
BOOL
(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE)(
    __in HANDLE hProcess,
    __in DWORD lpBaseAddress,
    __out_bcount(nSize) PVOID lpBuffer,
    __in DWORD nSize,
    __out PDWORD lpNumberOfBytesRead
    );
#endif
```

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[StackWalk64](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-stackwalk)