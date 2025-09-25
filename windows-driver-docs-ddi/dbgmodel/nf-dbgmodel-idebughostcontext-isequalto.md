# IDebugHostContext::IsEqualTo

## Description

Returns whether two [IDebugHostContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontext) objects are equal by value. Note that there is no requirement for a debug host to have interface pointer equality for two contexts which are equivalent. The actual contexts can be compared through this method.

## Parameters

### `pContext`

The host context to compare against.

### `pIsEqual`

An indication of whether the values of the two objects are equal.

## Return value

This method returns HRESULT.

## Remarks

## See also

[IDebugHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostcontext)