## Description

The GetValidRange method retrieves a set of module-relative addresses for which this storage is valid and whether it is guaranteed within said range.

## Parameters

### `start`

An output pointer to a ULONG64 type that receives the start address of the valid range.

### `end`

An output pointer to a ULONG64 type that receives the end address of the valid range.

### `guaranteed`

An output pointer to a bool type that indicates whether this storage is guaranteed within the valid range.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalStorage interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorage)