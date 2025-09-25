# IsImmersiveProcess function

## Description

Determines whether the process belongs to a Windows Store app.

## Parameters

### `hProcess` [in]

Target process handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).