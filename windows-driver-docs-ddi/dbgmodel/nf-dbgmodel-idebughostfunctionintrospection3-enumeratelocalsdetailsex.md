## Description

The EnumerateLocalsDetailsEx method enumerates a set of information about all locals and arguments within a function. Optionally, it can also enumerate all locals and arguments of functions inlined within the given function if 'enumerateInlinedLocals' is true. If the 'enumerateInlinedLocals' argument is false, this method behaves similarly to [EnumerateLocalsDetails](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostfunctionintrospection2-enumeratelocalsdetails).

## Parameters

### `enumerateInlinedLocals`

A boolean value. If true, the method will enumerate locals and arguments of inlined functions; otherwise, it will not.

### `localsEnum`

A pointer to a pointer variable that receives the [IDebugHostFunctionLocalDetailsEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetailsenumerator) of the enumerated locals details.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionIntrospection3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionintrospection3)