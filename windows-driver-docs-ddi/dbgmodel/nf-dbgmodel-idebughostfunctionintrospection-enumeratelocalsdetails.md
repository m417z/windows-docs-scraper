## Description

The EnumerateLocalsDetails method enumerates a set of information about all locals and arguments within a function. It doesn't enumerate any locals and arguments of functions inlined within the given function. To enumerate inlined functions, use the [EnumerateLocalsDetailsEx method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostfunctionintrospection2-enumeratelocalsdetailsex) on the IDebugHostFunctionIntrospection2 interface.

## Parameters

### `localsEnum`

A pointer to a pointer variable that receives the [IDebugHostFunctionLocalDetailsEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetailsenumerator) of the enumerated locals details.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionIntrospection interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionintrospection)