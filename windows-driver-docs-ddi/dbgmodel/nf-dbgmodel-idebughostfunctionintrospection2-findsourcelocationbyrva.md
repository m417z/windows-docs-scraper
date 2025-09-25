## Description

The FindSourceLocationByRVA method retrieves the source file name and the line number for a specific Relative Virtual Address (RVA).

## Parameters

### `rva`

A ULONG64 value that specifies the Relative Virtual Address.

### `sourceFile`

A pointer to a BSTR variable. This parameter receives the source file name.

### `sourceLine`

A pointer to a ULONG64 variable. This parameter receives the source line number.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionIntrospection2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionintrospection2)