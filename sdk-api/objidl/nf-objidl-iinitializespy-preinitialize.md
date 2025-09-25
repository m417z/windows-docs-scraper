# IInitializeSpy::PreInitialize

## Description

Performs initialization steps required before calling the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) function.

## Parameters

### `dwCoInit` [in]

The apartment type passed to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), specified as a member of the [COINIT](https://learn.microsoft.com/windows/desktop/api/objbase/ne-objbase-coinit) enumeration.

### `dwCurThreadAptRefs` [in]

The number of times [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) has been called on this thread.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)