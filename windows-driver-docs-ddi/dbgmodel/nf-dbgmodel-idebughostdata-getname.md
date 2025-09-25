# IDebugHostData::GetName

## Description

Returns the name of the symbol if the symbol has a name. If the symbol does not have a name, an error is returned.

## Parameters

### `symbolName`

The name of the symbol will be returned here as a string allocated via the SysAllocString method. The caller is responsible for freeing the allocated string via the SysFreeString method.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostData interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata)