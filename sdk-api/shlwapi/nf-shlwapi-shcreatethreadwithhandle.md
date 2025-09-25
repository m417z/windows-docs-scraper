# SHCreateThreadWithHandle function

## Description

Creates a new thread and retrieves its handle.

## Parameters

### `pfnThreadProc` [in]

Type: **LPTHREAD_START_ROUTINE**

A pointer to an application-defined function of type [LPTHREAD_START_ROUTINE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)). If a new thread was successfully created, this application-defined function is called in the context of that thread. **SHCreateThreadWithHandle** does not wait for the function pointed to by *pfnThreadProc* to complete before returning to its caller. The return value for the function specified by *pfnThreadProc* is the exit code of the thread.

### `pData` [in, optional]

Type: **void***

A pointer to an optional application-defined data structure that contains initialization data. It is passed to the function pointed to by *pfnThreadProc* and, optionally, the function pointed to by *pfnCallback*.

### `flags` [in]

Type: **SHCT_FLAGS**

Flags that control the behavior of the function; one or more of the [CTF](https://learn.microsoft.com/windows/desktop/shell/ctf) constants.

### `pfnCallback` [in, optional]

Type: **LPTHREAD_START_ROUTINE**

A pointer to an optional application-defined function of type [LPTHREAD_START_ROUTINE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686736(v=vs.85)). This function is called in the context of the created thread before the function pointed to by *pfnThreadProc* is called. It will also receive *pData* as its argument. **SHCreateThreadWithHandle** waits for the function pointed to by *pfnCallback* to complete before returning to its caller. The return value for the function specified by *pfnCallback* is ignored.

### `pHandle` [out, optional]

Type: **HANDLE***

A pointer to the **HANDLE** of the created thread. When it is no longer needed, this handle should be closed by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function. This value can be **NULL**.

## Return value

Type: **BOOL**

**TRUE** if the thread is successfully created; otherwise, **FALSE**

## Remarks

Prior to Windows 7, this function did not have an associated header or library file. To use this function under those earlier operating systems, call [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (Shlwapi.dll) to obtain a module handle. Then call [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) with that module handle and a function ordinal of 615 to get the address of this function.

The function pointed to by *pfnThreadProc* and *pfnCallback* must take the following form.

```
DWORD WINAPI ThreadProc(LPVOID pData)
{
    ...
}
```

The function name is arbitrary. The *pData* parameter points to an application-defined data structure with initialization information.

#### Examples

The following code example provides a function pointer prototype typedef for calling **SHCreateThreadWithHandle** by ordinal and shows how to accomplish such a call.

```cpp
// Define SHCREATETHREADWITHHANDLE as a function pointer to SHCreateThreadWithHandle.
typedef BOOL (STDMETHODCALLTYPE *SHCREATETHREADWITHHANDLE)(LPTHREAD_START_ROUTINE,
                                                           void *,
                                                           DWORD,
                                                           LPTHREAD_START_ROUTINE,
                                                           HANDLE *);

// CallSHCreateThreadWithHandle is an example function that:
// 1. Accepts parameters for the SHCreateThreadWithHandle function.
// 2. Loads Shlwapi.dll, which implements SHCreateThreadWithHandle.
// 3. Obtains the address of SHCreateThreadWithHandle in the loaded library.
// 4. Calls SHCreateThreadWithHandle through a SHCREATETHREADWITHHANDLE function pointer.

BOOL CallSHCreateThreadWithHandle(LPTHREAD_START_ROUTINE pfnThreadProc,
                                  void *pData,
                                  DWORD dwFlags,
                                  LPTHREAD_START_ROUTINE pfnCallback,
                                  HANDLE *pHandle)
{
    // Build a string that contains the local path to Shlwapi.dll.
    WCHAR szPath[MAX_PATH];
    GetSystemDirectory(szPath, ARRAYSIZE(szPath));
    PathAppend(szPath, L"shlwapi.dll");

    // Attempt to load Shlwapi.dll.
    HMODULE hModule = LoadLibrary(szPath);

    HRESULT hr = hModule ? S_OK : HRESULT_FROM_WIN32(GetLastError());
    if (SUCCEEDED(hr))
    {
        // Shlwapi.dll is loaded.
        // Before Windows 7, SHCreateThreadWithHandle must be accessed through
        // its ordinal. The following commented lines are used for this.

        // Get the address of SHCreateThreadWithHandle through its ordinal value of 615.
        // SHCREATETHREADWITHHANDLE pfn =
        //     (SHCREATETHREADWITHHANDLE)GetProcAddress(hModule, MAKEINTRESOURCEA(615));
        //
        // hr = pfn ? S_OK : HRESULT_FROM_WIN32(GetLastError());
        //
        // if (SUCCEEDED(hr))
        // {
        //     // Call SHCreateThreadWithHandle through SHCREATETHREADWITHHANDLE.
        //     hr = pfn(pfnThreadProc, pData, dwFlags, pfnCallback, pHandle)
        //               ? S_OK : HRESULT_FROM_WIN32(GetLastError());
        // }
        // FreeLibrary(hModule);

        hr = SHCreateThreadWithHandle(pfnThreadProc, pData, dwFlags, pfnCallback, pHandle)
                       ? S_OK : HRESULT_FROM_WIN32(GetLastError());
    }
    return SUCCEEDED(hr);
}
```

## See also

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[GetSystemDirectory](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemdirectorya)

[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)