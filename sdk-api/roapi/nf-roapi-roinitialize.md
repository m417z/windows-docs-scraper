# RoInitialize function

## Description

Initializes the Windows Runtime on the current thread with the specified concurrency model.

## Parameters

### `initType` [in]

Type: **[RO_INIT_TYPE](https://learn.microsoft.com/windows/desktop/api/roapi/ne-roapi-ro_init_type)**

The concurrency model for the thread. The default is **RO_INIT_MULTITHREADED**.

## Return value

Type: **HRESULT**

This function can return the standard return values **E_INVALIDARG**, **E_OUTOFMEMORY**, and **E_UNEXPECTED**, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The Windows Runtime was initialized successfully on this thread. |
| **S_FALSE** | The Windows Runtime is already initialized on this thread. |
| **RPC_E_CHANGED_MODE** | A previous call to [RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize) specified the concurrency model for this thread as multithread apartment (MTA). This could also indicate that a change from neutral-threaded apartment to single-threaded apartment has occurred. |

## Remarks

Use the **RoInitialize** function to initialize a thread in the Windows Runtime. All threads that activate and interact with Windows Runtime objects must be initialized prior to calling into the Windows Runtime.

Call the [RoUninitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-rouninitialize) function to close the Windows Runtime on the current thread. Each successful call to **RoInitialize**, including those that return **S_FALSE**, must be balanced by a corresponding call to **RoUninitialize**.

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[RO_INIT_TYPE](https://learn.microsoft.com/windows/desktop/api/roapi/ne-roapi-ro_init_type)

[RoUninitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-rouninitialize)