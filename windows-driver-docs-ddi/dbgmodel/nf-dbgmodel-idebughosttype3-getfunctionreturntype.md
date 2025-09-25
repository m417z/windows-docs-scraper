## Description

The GetFunctionReturnType method returns the return type of the function.

## Parameters

### `returnType`

A type symbol indicating the return type of the function is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for a function (see FindTypeByName) */

ComPtr<IDebugHostType> spReturnType;
if (SUCCEEDED(spType->GetFunctionReturnType(&spReturnType)))
{
    // spReturnType is the type symbol for the return type of the function.
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)