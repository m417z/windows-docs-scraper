## Description

The GetLocalKind method retrieves the kind of local variable that has been enumerated.

## Parameters

### `kind`

A pointer to a [LocalKind variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-localkind). This parameter receives the kind of the local variable.

## Return value

## Remarks

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[IDebugHostFunctionLocalDetails interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetails)