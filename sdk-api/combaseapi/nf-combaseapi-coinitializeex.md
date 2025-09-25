# CoInitializeEx function

## Description

Initializes the COM library for use by the calling thread, sets the thread's concurrency model, and creates a new apartment for the thread if one is required.

You should call Windows::Foundation::Initialize to initialize the thread instead of **CoInitializeEx** if you want to use the Windows Runtime APIs or if you want to use both COM and Windows Runtime components. Windows::Foundation::Initialize is sufficient to use for COM components.

## Parameters

### `pvReserved` [in, optional]

This parameter is reserved and must be **NULL**.

### `dwCoInit` [in]

The concurrency model and initialization options for the thread. Values for this parameter are taken from the [COINIT](https://learn.microsoft.com/windows/desktop/api/objbase/ne-objbase-coinit) enumeration. Any combination of values from **COINIT** can be used, except that the COINIT_APARTMENTTHREADED and COINIT_MULTITHREADED flags cannot both be set. The default is COINIT_MULTITHREADED.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The COM library was initialized successfully on this thread. |
| **S_FALSE** | The COM library is already initialized on this thread. |
| **RPC_E_CHANGED_MODE** | A previous call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) specified an incompatible concurrency model for this thread. This could also indicate that a change from neutral-threaded apartment to single-threaded apartment has occurred. |

## Remarks

**CoInitializeEx** must be called at least once, and is usually called only once, for each thread that uses the COM library. Multiple calls to **CoInitializeEx** by the same thread are allowed as long as they pass the same concurrency flag, but subsequent valid calls return S_FALSE.
If the concurrency flag does not match, then the call fails and returns RPC_E_CHANGED_MODE.
(For the purpose of this rule, a call to [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) is equivalent to calling **CoInitializeEx** with the COINIT_APARTMENTTHREADED flag.)
To uninitialize the COM library gracefully on a thread, each successful call to [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or **CoInitializeEx**, including any call that returns S_FALSE, must be balanced by a corresponding call to [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize).
Once COM has been uninitialized on a thread, you can reinitialize it in any mode, subject to the constraints above.

You need to initialize the COM library on a thread before you call any of the library functions except [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc), to get a pointer to the standard allocator, and the memory allocation functions.
Otherwise, the COM function will return CO_E_NOTINITIALIZED.

Objects created in a single-threaded apartment (STA) receive method calls only from their apartment's thread, so calls are serialized and arrive only at message-queue boundaries (when the [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) or [SendMessage](https://learn.microsoft.com/previous-versions/windows/desktop/oe/oe-ihttpmailtransport-sendmessage) function is called).

Objects created on a COM thread in a multithread apartment (MTA) must be able to receive method calls from other threads at any time. You would typically implement some form of concurrency control in a multithreaded object's code using synchronization primitives such as critical sections, semaphores, or mutexes to help protect the object's data.

When an object that is configured to run in the neutral threaded apartment (NTA) is called by a thread that is in either an STA or the MTA, that thread transfers to the NTA. If this thread subsequently calls **CoInitializeEx**, the call fails and returns RPC_E_CHANGED_MODE.

Because OLE technologies are not thread-safe, the [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) function calls **CoInitializeEx** with the COINIT_APARTMENTTHREADED flag. As a result, an apartment that is initialized for multithreaded object concurrency cannot use the features enabled by **OleInitialize**.

Because there is no way to control the order in which in-process servers are loaded or unloaded, do not call [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize), **CoInitializeEx**, or [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) from the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function.

## See also

[Processes, Threads, and Apartments](https://learn.microsoft.com/windows/desktop/com/processes--threads--and-apartments)