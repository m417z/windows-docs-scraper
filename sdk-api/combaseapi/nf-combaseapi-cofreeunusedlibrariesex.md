## Description

Unloads any DLLs that are no longer in use and whose unload delay has expired.

## Parameters

### `dwUnloadDelay` [in]

The delay in milliseconds between the time that the DLL has stated it can be unloaded until it becomes a candidate to unload. Setting this parameter to INFINITE uses the system default delay (10 minutes). Setting this parameter to 0 forces the unloading of any DLLs without any delay.

### `dwReserved` [in]

This parameter is reserved and must be 0.

## Remarks

COM supplies functions to reclaim memory held by DLLs containing components. The most commonly used function is [CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries). **CoFreeUnusedLibraries** does not immediately release DLLs that have no active object. There is a 10-minute delay for multithreaded apartments (MTAs) and neutral apartments (NAs). For single-threaded apartments (STAs), there is no delay.

The 10-minute delay for [CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries) is to avoid multithread race conditions caused by unloading a component DLL. This default delay may be too long for many applications.

COM maintains a list of active DLLs that have had components loaded for the apartments that can be hosted on the thread where this function is called. When **CoFreeUnusedLibrariesEx** is called, each DLL on that list has its [DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) function called. If **DllCanUnloadNow** returns S_FALSE (or is not exported), this DLL is not ready to be unloaded. If **DllCanUnloadNow** returns S_OK, this DLL is moved off the active list to a "candidate-for-unloading" list.

Adding the DLL to the candidate-for-unloading list time-stamps the DLL *dwUnloadDelay* milliseconds from when this move occurs. When **CoFreeUnusedLibrariesEx** (or [CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries)) is called again, at least *dwUnloadDelay* milliseconds from the call that moved the DLL to the candidate-for-unloading list, the DLL is actually freed from memory. If COM uses the component DLL while the DLL is on the candidate-for-unloading list, it is moved back to the active list.

Setting *dwUnloadDelay* to 0 may have unexpected consequences. The component DLL may need some time for cleanup after it returns from the [DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow) function. For example, if the DLL had its own worker threads, using a value of 0 would most likely lead to a problem because the code executing on these threads would be unmapped, caused by the unloading of the DLL before the worker threads have a chance to exit. Also, using too brief of a value for *dwUnloadDelay* can lead to performance issues because there is more overhead in reloading a DLL than letting it page out.

This behavior is triggered by the DLL supplying components with threading models set to Free, Neutral, or Both. For a threading model set to Apartment (or if no threading model is specified), *dwUnloadDelay* is treated as 0 because these components are tied to the single thread hosting the apartment.

## See also

[CoFreeAllLibraries](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreealllibraries)

[CoFreeLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cofreelibrary)

[CoFreeUnusedLibraries](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cofreeunusedlibraries)

[CoLoadLibrary](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coloadlibrary)

[DllCanUnloadNow](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-dllcanunloadnow)