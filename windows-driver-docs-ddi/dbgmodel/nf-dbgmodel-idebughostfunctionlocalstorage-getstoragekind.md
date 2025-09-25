## Description

The GetStorageKind method retrieves the storage kind of the local data.

## Parameters

### `kind`

An output pointer to a [StorageKind type](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-storagekind) that receives the kind of local storage.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalStorage interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorage)