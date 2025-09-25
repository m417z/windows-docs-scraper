## Description

Sets the handle for the input, output, or error streams.

## Parameters

### `nStdHandle`

A DWORD indicating the stream for which the handle is being set.

### `hHandle`

The handle.

### `phPrevValue`

Optional. Receives the previous handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

## See also