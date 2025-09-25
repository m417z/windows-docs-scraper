## Description

The GetExtendedRegisterAddressInfo method retrieves the architecture-specific register address information in which local data is stored. The information includes the register ID, the offset, whether the access is indirect, and the indirect offset if applicable.

## Parameters

### `registerId`

An output pointer to a ULONG type that will receive the ID of the register where the local is stored.

### `offset`

An output pointer to a LONG64 type that receives the offset from the register.

### `isIndirectAccess`

An output pointer to a bool type that indicates whether the access to this storage is indirect.

### `indirectOffset`

An output pointer to a LONG type that receives the offset if the access is indirect.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalStorage2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorage2)