## Description

The GetContext method returns the context where the symbol is valid. While this will represent things such as the debug target and process/address space in which the symbol exists, it may not be as specific as a context retrieved from other means (e.g.: from an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)).

## Parameters

### `context`

The host context in which the symbol is located will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)