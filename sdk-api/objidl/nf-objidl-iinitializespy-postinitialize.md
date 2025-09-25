# IInitializeSpy::PostInitialize

## Description

Performs initialization steps required after calling the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) function.

## Parameters

### `hrCoInit` [in]

The value returned by [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex).

### `dwCoInit` [in]

The apartment type passed to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex), specified as a member of the [COINIT](https://learn.microsoft.com/windows/desktop/api/objbase/ne-objbase-coinit) enumeration.

### `dwNewThreadAptRefs` [in]

The number of times [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) has been called on this thread.

## Return value

This method returns the value that it intends the [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) call to return to its caller. For more information, see the Remarks section.

## Remarks

The return value from **PostInitialize** is intended to be the returned **HRESULT** from the call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex). This is always the case for a single active registration on this thread.

For cases where there are multiple registrations active on this thread, the returned **HRESULT** is arrived at by chaining of the various **PostInitialize** methods as follows: The COM determined **HRESULT** will be passed as the *hrCoInit* parameter to the first **PostInitialize** method called. The **HRESULT** from that **PostInitialize** call will be passed as the *hrCoInit* parameter to the next **PostInitialize** call. This chaining continues leading to the **HRESULT** from the last **PostInitialize** call being returned as the **HRESULT** from the call to [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex).

## See also

[CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex)

[IInitializeSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinitializespy)