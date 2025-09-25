## Description

The FinalizeContext method finalizes modifications of the host context, makes it immutable, and returns an interface to the context.

## Parameters

### `immutableContext`

A pointer to a pointer variable that receives the IDebugHostContext interface to the immutable context.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostContextExtension interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontextextension)