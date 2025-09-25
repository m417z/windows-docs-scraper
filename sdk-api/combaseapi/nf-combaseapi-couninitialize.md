# CoUninitialize function

## Description

Closes the COM library on the current thread, unloads all DLLs loaded by the thread, frees any other resources that the thread maintains, and forces all RPC connections on the thread to close.

## Remarks

A thread must call **CoUninitialize** once for each successful call it has made to the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) function, including any call that returns S_FALSE. Only the **CoUninitialize** call corresponding to the **CoInitialize** or **CoInitializeEx** call that initialized the library can close it.

Calls to [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) must be balanced by calls to [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize). The **OleUninitialize** function calls **CoUninitialize** internally, so applications that call **OleUninitialize** do not also need to call **CoUninitialize**.

**CoUninitialize** should be called on application shutdown, as the last call made to the COM library after the application hides its main windows and falls through its main message loop. If there are open conversations remaining, **CoUninitialize** starts a modal message loop and dispatches any pending messages from the containers or server for this COM application. By dispatching the messages, **CoUninitialize** ensures that the application does not quit before receiving all of its pending messages. Non-COM messages are discarded.

Because there is no way to control the order in which in-process servers are loaded or unloaded, do not call [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize), [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), or **CoUninitialize** from the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function.

## See also

[CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize)

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize)