# SetThreadDescription function

## Description

Assigns a description to a thread.

## Parameters

### `hThread` [in]

A handle for the thread for which you want to set the description. The handle must have THREAD_SET_LIMITED_INFORMATION access.

### `lpThreadDescription` [in]

A Unicode string that specifies the description of the thread.

## Return value

If the function succeeds, the return value is the **HRESULT** that denotes a successful operation.
If the function fails, the return value is an **HRESULT** that denotes the error.

## Remarks

The description of a thread can be set more than once; the most recently set value is used. You can retrieve the description of a thread by calling [GetThreadDescription](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreaddescription).

**Windows Server 2016**, **Windows 10 LTSB 2016** and **Windows 10 version 1607**: SetThreadDescription is only available by [Run Time Dynamic Linking](https://learn.microsoft.com/windows/win32/dlls/using-run-time-dynamic-linking) in KernelBase.dll.

#### Examples

The following example sets the description for the current thread to `simulation_thread`.

```cpp
HRESULT hr = SetThreadDescription(GetCurrentThread(), L"simulation_thread");
if (FAILED(hr))
{
    // Call failed.
}
```

## See also

[GetThreadDescription](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getthreaddescription), [How to: Set a Thread Name in Native Code](https://learn.microsoft.com/visualstudio/debugger/how-to-set-a-thread-name-in-native-code)