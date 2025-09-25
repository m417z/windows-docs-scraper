## Description

The EnumerateStorage method enumerates the storage for the local variable, including what registers or memory locations it may be in within the function.

## Parameters

### `storageEnum`

A pointer to a pointer variable that receives the [IDebugHostFunctionLocalStorageEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorageenumerator) of the enumerated local storage locations.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalDetails2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocaldetails2)