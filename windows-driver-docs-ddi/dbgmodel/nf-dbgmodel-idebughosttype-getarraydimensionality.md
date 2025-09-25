# IDebugHostType::GetArrayDimensionality

## Description

The GetArrayDimensionality method returns the number of dimensions that the array is indexed in. For C style arrays, the value returned here will always be 1.

## Parameters

### `arrayDimensionality`

The number of dimensions that the array is indexed in will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for some array (see FindTypeByName) */

ULONG64 arrayDims;
if (SUCCEEDED(spType->GetArrayDimensionality(&arrayDims)))
{
    // arrayDims is the dimensionality of the array.  For C/C++, this is always 1.
}
```

## See also

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)