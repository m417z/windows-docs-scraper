# OleInitialize function

## Description

Initializes the COM library on the current apartment, identifies the concurrency model as single-thread apartment (STA), and enables additional functionality described in the Remarks section below. Applications must initialize the COM library before they can call COM library functions other than [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc) and memory allocation functions.

## Parameters

### `pvReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The COM library is already initialized on this apartment. |
| **OLE_E_WRONGCOMPOBJ** | The versions of COMPOBJ.DLL and OLE2.DLL on your machine are incompatible with each other. |
| **RPC_E_CHANGED_MODE** | A previous call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) specified the concurrency model for this apartment as multithread apartment (MTA). This could also mean that a change from neutral threaded apartment to single threaded apartment occurred. |

## Remarks

Applications that use the following functionality must call **OleInitialize** before calling any other function in the COM library:

* Clipboard
* Drag and Drop
* Object linking and embedding (OLE)
* In-place activation

**OleInitialize** calls [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) internally to initialize the COM library on the current apartment. Because OLE operations are not thread-safe, **OleInitialize** specifies the concurrency model as single-thread apartment.

Once the concurrency model for an apartment is set, it cannot be changed. A call to **OleInitialize** on an apartment that was previously initialized as multithreaded will fail and return RPC_E_CHANGED_MODE.

You need to initialize the COM library on an apartment before you call any of the library functions except [CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc), to get a pointer to the standard allocator, and the memory allocation functions.

Typically, the COM library is initialized on an apartment only once. Subsequent calls will succeed, as long as they do not attempt to change the concurrency model of the apartment, but will return S_FALSE. To close the COM library gracefully, each successful call to **OleInitialize**, including those that return S_FALSE, must be balanced by a corresponding call to [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize).

Because there is no way to control the order in which in-process servers are loaded or unloaded, do not call **OleInitialize** or [OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize) from the [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function.

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[OleInitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleinitialize)

[OleUninitialize](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleuninitialize)