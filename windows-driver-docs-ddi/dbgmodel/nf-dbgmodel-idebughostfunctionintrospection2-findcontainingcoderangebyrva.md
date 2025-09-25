## Description

The FindContainingCodeRangeByRVA method returns the sub-range of instructions that contains a given address. For single-block functions, this will simply be the start and end of the function body. For multi-block functions, this will be the start and end of the block containing the specified Relative Virtual Address (RVA).

## Parameters

### `rva`

A ULONG64 value that specifies the Relative Virtual Address.

### `rangeStart`

A pointer to a Location structure. This parameter receives the starting location of the code range.

### `rangeEnd`

A pointer to a Location structure. This parameter receives the ending location of the code range.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionIntrospection2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionintrospection2)