# IInitializeSpy::PostUninitialize

## Description

Performs cleanup steps required after calling the [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) function.

## Parameters

### `dwNewThreadAptRefs` [in]

The number of calls to [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) remaining on this thread.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)