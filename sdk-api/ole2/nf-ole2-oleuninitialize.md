# OleUninitialize function

## Description

Closes the COM library on the apartment, releases any class factories, other COM objects, or servers held by the apartment, disables RPC on the apartment, and frees any resources the apartment maintains.

## Remarks

Call **OleUninitialize** on application shutdown, as the last COM library call, if the apartment was initialized with a call to [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize). **OleUninitialize** calls the [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) function internally to shut down the OLE Component Object(COM) Library.

If the COM library was initialized on the apartment with a call to [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), it must be closed with a call to [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize).

The [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) and **OleUninitialize** calls must be balanced. If there are multiple calls to the **OleInitialize** function, there must be the same number of calls to **OleUninitialize**; only the **OleUninitialize** call corresponding to the **OleInitialize** call that actually initialized the library can close it.

Because there is no way to control the order in which in-process servers are loaded or unloaded, do not call [OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize) or **OleUninitialize** from the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function.

## See also

[OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize)

[OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize)