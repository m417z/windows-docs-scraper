## Description

The GetContainingType method returns the type of the containing parent (the type that contains this symbol).

## Parameters

### `containingParentType`

A pointer to a pointer variable that receives the [IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3) of the containing parent's type.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostField2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield2)