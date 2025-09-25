## Description

The GetPrimaryCompilerInformationmethod retrieves information regarding the "primary compiler" which produced the module. The returned information can be used, for example, to understand how symbols are formatted by that compiler. Although this can vary for each compilation unit or compiland, this method should return the details of the "primary" or most significant one for non-assembly compilation units.

It is important to note that the "compiler string" returned may either be a compiler name or it may contain additional information such as command line arguments depending on the underlying implementation. It is also possible for a debug host to return E_NOTIMPL for this call.

## Parameters

### `pCompilerId`

Pointer to where the identifier of the primary compiler will be stored.

### `pPrimaryCompilerString`

Optional pointer to where the string representation of the primary compiler will be stored.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostModule5 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule5)