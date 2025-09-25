# ReadProcessMemory function

## Description

Reads data from an area of memory in a specified process. The entire area to be read must be accessible or the operation fails.

## Parameters

### `hProcess` [in]

A handle to the process with memory that is being read. The handle must have PROCESS_VM_READ access to the process.

### `lpBaseAddress` [in]

A pointer to the base address in the specified process from which to read. Before any data transfer occurs, the system verifies that all data in the base address and memory of the specified size is accessible for read access, and if it is not accessible the function fails.

### `lpBuffer` [out]

A pointer to a buffer that receives the contents from the address space of the specified process.

### `nSize` [in]

The number of bytes to be read from the specified process.

### `lpNumberOfBytesRead` [out]

A pointer to a variable that receives the number of bytes transferred into the specified buffer. If *lpNumberOfBytesRead* is **NULL**, the parameter is ignored.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The function fails if the requested read operation crosses into an area of the process that is inaccessible.

## Remarks

**ReadProcessMemory** copies the data in the specified address range from the address space of the specified process into the specified buffer of the current process. Any process that has a handle with PROCESS_VM_READ access can call the function.

The entire area to be read must be accessible, and if it is not accessible, the function fails.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/win32/debug/debugging-functions), [OpenProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess), [Process Functions for Debugging](https://learn.microsoft.com/windows/win32/debug/process-functions-for-debugging), [VirtualAllocEx](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-virtualallocex), [WriteProcessMemory](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory)