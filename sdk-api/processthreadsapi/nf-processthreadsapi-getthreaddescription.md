# GetThreadDescription function

## Description

Retrieves the description that was assigned to a thread by calling [SetThreadDescription](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setthreaddescription).

## Parameters

### `hThread` [in]

A handle to the thread for which to retrieve the description. The handle must have THREAD_QUERY_LIMITED_INFORMATION access.

### `ppszThreadDescription` [out]

A Unicode string that contains the description of the thread.

## Return value

If the function succeeds, the return value is the **HRESULT** that denotes a successful operation.
If the function fails, the return value is an **HRESULT** that denotes the error.

## Remarks

**Windows Server 2016**, **Windows 10 LTSB 2016** and **Windows 10 version 1607**: GetThreadDescription is only available by [Run Time Dynamic Linking](https://learn.microsoft.com/windows/win32/dlls/using-run-time-dynamic-linking) in KernelBase.dll.

The description for a thread can change at any time. For example, a different thread can change the description of a thread of interest while you try to retrieve that description.

Thread descriptions do not need to be unique.

To free the memory for the thread description, call the [LocalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree) method.

#### Examples

The following example gets the description for a thread, prints the description, and then frees the memory for the description.

```cpp
HRESULT hr = GetThreadDescription(ThreadHandle, &data);
if (SUCCEEDED(hr))
{
    wprintf(L"%ls\n", data);
    LocalFree(data);
}
```

## See also

[LocalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree), [SetThreadDescription](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-setthreaddescription)