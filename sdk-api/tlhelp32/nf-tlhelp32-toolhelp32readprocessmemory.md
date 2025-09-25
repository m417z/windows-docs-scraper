# Toolhelp32ReadProcessMemory function

## Description

Copies memory allocated to another process into an application-supplied buffer.

## Parameters

### `th32ProcessID` [in]

The identifier of the process whose memory is being copied. This parameter can be zero to copy the memory of the current process.

### `lpBaseAddress` [in]

The base address in the specified process to read. Before transferring any data, the system verifies that all data in the base address and memory of the specified size is accessible for read access. If this is the case, the function proceeds. Otherwise, the function fails.

### `lpBuffer` [out]

A pointer to a buffer that receives the contents of the address space of the specified process.

### `cbRead` [in]

The number of bytes to read from the specified process.

### `lpNumberOfBytesRead` [out]

The number of bytes copied to the specified buffer. If this parameter is **NULL**, it is ignored.

## Return value

Returns **TRUE** if successful.

## Remarks

This function opens a handle to the target process and closes it once the read operation has completed. If you're planning to perform several reads, use [ReadProcessMemory](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-readprocessmemory) instead.

## See also

[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first)

[Process32Next](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32next)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)