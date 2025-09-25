## Description

The GetRegister method retrieves the register the local data is stored within, or the register it is relative to. The returned value is architecture-specific.

## Parameters

### `registerId`

An output pointer to a ULONG type that receives the architecture-specific register ID where the local is stored.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also

[IDebugHostFunctionLocalStorage interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfunctionlocalstorage)