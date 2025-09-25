# FlushInstructionCache function

## Description

Flushes the instruction cache for the specified process.

## Parameters

### `hProcess` [in]

A handle to a process whose instruction cache is to be flushed.

### `lpBaseAddress` [in]

A pointer to the base of the region to be flushed. This parameter can be **NULL**.

### `dwSize` [in]

The size of the region to be flushed if the *lpBaseAddress* parameter is not **NULL**, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications should call
**FlushInstructionCache** if they generate or modify code in memory. The CPU cannot detect the change, and may execute the old code it cached.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)