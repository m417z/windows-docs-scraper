## Description

The GetNext method retrieves information about the next local variable within the function. Note that this method is "scopeless", meaning that it might return two local variables with the same name as they might be in different scopes.

## Parameters

### `storage`

A pointer to a pointer variable that receives the [IDebugHostFunctionLocalStorage interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorage) of the next local variable's details.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## See also

[IDebugHostFunctionLocalStorageEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorageenumerator)