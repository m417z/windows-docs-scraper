# IsProcessCritical function

## Description

Determines whether the specified process is considered critical.

## Parameters

### `hProcess` [in]

A handle to the process to query. The process must have been opened with **PROCESS_QUERY_LIMITED_INFORMATION** access.

### `Critical` [out]

A pointer to the **BOOL** value this function will use to indicate whether the process is considered critical.

## Return value

This routine returns FALSE on failure. Any other value indicates success. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to query for the specific error reason on failure.

## See also

[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32)