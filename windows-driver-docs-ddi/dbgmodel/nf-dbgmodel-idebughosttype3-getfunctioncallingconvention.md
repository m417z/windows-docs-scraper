## Description

The GetFunctionCallingConvention method returns the calling convention of the function. Such is returned as a member of the [CallingConventionKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-callingconventionkind).

## Parameters

### `conventionKind`

The calling convention of the function is returned here as a member of the [CallingConventionKind enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/ne-dbgmodel-callingconventionkind).

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostModule> spType; /* get a type for some function type (see FindTypeByName) */

CallingConventionKind conv;
if (SUCCEEDED(spType->GetCallingConvention(&conv)))
{
    // conv indicates the calling convention (e.g.: cdecl, thiscall, etc...)
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)