# SHCreateThread function

## Description

Creates a thread.

## Parameters

### `pfnThreadProc` [in]

Type: **LPTHREAD_START_ROUTINE**

A pointer to an application-defined function of the [LPTHREAD_START_ROUTINE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)) type. If a new thread was successfully created, this application-defined function is called in the context of that thread. **SHCreateThread** does not wait for the function pointed to by this parameter to complete before returning to its caller. The application-defined function's return value is the exit code of the thread.

### `pData` [in, optional]

Type: **void***

A pointer to an optional application-defined data structure that contains initialization data. It is passed to the function pointed to by *pfnThreadProc* and, optionally, *pfnCallback*. This value can be **NULL**.

### `flags` [in]

Type: **SHCT_FLAGS**

The flags that control the behavior of the function. One or more of the [CTF](https://learn.microsoft.com/windows/desktop/shell/ctf) constants.

### `pfnCallback` [in, optional]

Type: **LPTHREAD_START_ROUTINE**

A pointer to an optional application-defined function of the
[LPTHREAD_START_ROUTINE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)) type. This function is called
in the context of the created thread before the function pointed to by
*pfnThreadProc* is called. It will also receive *pData* as
its argument. **SHCreateThread** will wait for the
function pointed to by *pfnCallback* to return before returning to its caller. The
return value of the function pointed to by *pfnCallback* is ignored.

## Return value

Type: **BOOL**

Returns **TRUE** if the thread is successfully created, or **FALSE** otherwise. On failure, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to retrieve the specific error value as shown here.

```
if (!SHCreateThread(...))
{
    hr = HRESULT_FROM_WIN32( GetLastError() );
}
else
{
    ....
}
```

## Remarks

The function pointed to by *pfnThreadProc* and *pfnCallback* must take the following form.

```
DWORD WINAPI ThreadProc(LPVOID pData)
{
  ...
}
```

The function name is arbitrary. The *pData* parameter points to an application-defined data structure with initialization information.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[SHCreateThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shcreatethreadref)

[SHGetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shgetthreadref)

[SHReleaseThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shreleasethreadref)

[SHSetThreadRef](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shsetthreadref)

[Shell and Common Controls Versions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85))