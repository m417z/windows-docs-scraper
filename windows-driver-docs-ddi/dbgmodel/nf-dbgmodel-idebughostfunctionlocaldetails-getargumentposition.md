## Description

The GetArgumentPosition method obtains the position of the function argument within the argument list. This method will fail on any local which does not return LocalArgument from the [GetLocalKind() method](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nf-dbgmodel-idebughostfunctionlocaldetails-getlocalkind).

## Parameters

### `argPosition`

A pointer to a ULONG64 variable. This parameter receives the position of the argument within the argument list.

## Return value

f the method succeeds, it returns S_OK. If the local does not return LocalArgument from the GetLocalKind() method, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalDetails interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetails)