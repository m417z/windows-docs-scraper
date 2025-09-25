# SHFreeShared function

## Description

[**SHFreeShared** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Frees shared memory, regardless of which process allocated it.

## Parameters

### `hData` [in]

Type: **HANDLE**

A handle to the mapped memory.

### `dwProcessId` [in]

Type: **DWORD**

The process ID of the process from which the memory was allocated.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[SHAllocShared](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shallocshared)