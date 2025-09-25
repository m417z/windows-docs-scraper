# IDebugHostSymbol2::CompareAgainst

## Description

Compares two symbols for equality. A host is under no obligation to ensure that there is interface pointer equality for two identical symbols. This can be used to check for equality.

Note that presently, "comparisonFlags" is reserved.

## Parameters

### `pComparisonSymbol`

The symbol to compare against.

### `comparisonFlags`

Reserved. Must be set to 0.

### `pMatches`

An indication of whether the symbols are equal will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostSymbol2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbol2)