# IDebugHostSymbolEnumerator::GetNext

## Description

Moves the iterator forward and fetches the next symbol in the set.

E_BOUNDS will be returned when the enumerator hits the end of the set.

## Parameters

### `symbol`

The next enumerated symbol will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDebugHostSymbolEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostsymbolenumerator)