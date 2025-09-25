# WriteProcessMemory function

## Description

Writes data to an area of memory in a specified process. The entire area to be written to must be accessible or the operation fails.

## Parameters

### `hProcess` [in]

A handle to the process memory to be modified. The handle must have PROCESS_VM_WRITE and PROCESS_VM_OPERATION access to the process.

### `lpBaseAddress` [in]

A pointer to the base address in the specified process to which data is written. Before data transfer occurs, the system verifies that all data in the base address and memory of the specified size is accessible for write access, and if it is not accessible, the function fails.

### `lpBuffer` [in]

A pointer to the buffer that contains data to be written in the address space of the specified process.

### `nSize` [in]

The number of bytes to be written to the specified process.

### `lpNumberOfBytesWritten` [out]

A pointer to a variable that receives the number of bytes transferred into the specified process. This parameter is optional. If *lpNumberOfBytesWritten* is **NULL**, the parameter is ignored.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The function fails if the requested write operation crosses into an area of the process that is inaccessible.

## Remarks

**WriteProcessMemory** copies the data from the specified buffer in the current process to the address range of the specified process. Any process that has a handle with PROCESS_VM_WRITE and PROCESS_VM_OPERATION access to the process to be written to can call the function. Typically but not always, the process with address space that is being written to is being debugged.

The entire area to be written to must be accessible, and if it is not accessible, the function fails.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[Process Functions for Debugging](https://learn.microsoft.com/windows/desktop/Debug/process-functions-for-debugging)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[VirtualAllocEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualallocex)