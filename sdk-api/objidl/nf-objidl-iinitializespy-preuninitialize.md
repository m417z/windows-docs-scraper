# IInitializeSpy::PreUninitialize

## Description

Performs cleanup steps required before calling the [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) function.

## Parameters

### `dwCurThreadAptRefs` [in]

The number of times [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) has been called on this thread.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)