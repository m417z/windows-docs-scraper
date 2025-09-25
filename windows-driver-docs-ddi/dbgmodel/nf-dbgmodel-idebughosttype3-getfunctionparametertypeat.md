## Description

The GetFunctionParameterTypeAt method returns the type of the i-th argument to the function.

## Parameters

### `i`

A zero based index into the function argument list for which to retrieve the argument type.

### `parameterType`

The type of the i-th argument to the function will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for a function (see FindTypeByName) */

// enumerate (in order) the types of parameters the function takes
ULONG64 count;
if (SUCCEEDED(spType->GetFunctionParameterTypeCount(&count)))
{
    for (ULONG64 i = 0; i < count; ++i)
    {
        ComPtr<IDebugHostType> spParamType;
        if (SUCCEEDED(spType->GetFunctionParameterTypeAt(i, &spParamType)))
        {
            // spParamType is the type symbol for the type of parameter the
            // function takes at position i in the argument list.
        }
    }
}
```

## See also

[IDebugHostType3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype3)