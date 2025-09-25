# CoInitialize function

## Description

Initializes the COM library on the current thread and identifies the concurrency model as single-thread apartment (STA).

New applications should call [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) instead of CoInitialize.

If you want to use the Windows Runtime, you must call [RoInitialize](https://learn.microsoft.com/windows/win32/api/roapi/nf-roapi-roinitialize) or [Windows::Foundation::Initialize](https://learn.microsoft.com/windows/win32/api/roapi/nf-roapi-initialize) instead.

## Parameters

### `pvReserved` [in, optional]

This parameter is reserved and must be **NULL**.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The COM library was initialized successfully on this thread. |
| **S_FALSE** | The COM library is already initialized on this thread. |
| **RPC_E_CHANGED_MODE** | A previous call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) specified the concurrency model for this thread as multithread apartment (MTA). This could also indicate that a change from neutral-threaded apartment to single-threaded apartment has occurred. |

## Remarks

You need to initialize the COM library on a thread before you call any of the library functions except [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc), to get a pointer to the standard allocator, and the memory allocation functions.

After the concurrency model for a thread is set, it cannot be changed. A call to **CoInitialize** on an apartment that was previously initialized as multithreaded will fail and return RPC_E_CHANGED_MODE.

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) provides the same functionality as **CoInitialize** and also provides a parameter to explicitly specify the thread's concurrency model. **CoInitialize** calls **CoInitializeEx** and specifies the concurrency model as single-thread apartment. Applications developed today should call **CoInitializeEx** rather than **CoInitialize**.

Typically, the COM library is initialized on a thread only once. Subsequent calls to **CoInitialize** or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) on the same thread will succeed, as long as they do not attempt to change the concurrency model, but will return S_FALSE. To close the COM library gracefully, each successful call to **CoInitialize** or **CoInitializeEx**, including those that return S_FALSE, must be balanced by a corresponding call to [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize). However, the first thread in the application that calls **CoInitialize** with 0 (or **CoInitializeEx** with COINIT_APARTMENTTHREADED) must be the last thread to call **CoUninitialize**. Otherwise, subsequent calls to **CoInitialize** on the STA will fail and the application will not work.

Because there is no way to control the order in which in-process servers are loaded or unloaded, do not call **CoInitialize**, [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) from the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function.

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)