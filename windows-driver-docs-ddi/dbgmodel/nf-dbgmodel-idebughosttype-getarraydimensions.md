# IDebugHostType::GetArrayDimensions

## Description

The GetArrayDimensions method returns a set of descriptors, one for each dimension of the array as indicated by the GetArrayDimensionality method. Each descriptor is an ArrayDimension structure which describes the starting index, length, and forward stride of each array dimension. This allows descriptions of significantly more powerful array constructs than are allowed in the C type system.

For C-style arrays, a single array dimension is returned here with values which are always:

- LowerBound = 0
- Length = ARRAYSIZE(array)
- Stride = sizeof(elementType)

## Parameters

### `dimensions`

Indicates the number of dimension descriptors to fetch. This must be the value acquired from a call to GetArrayDimensionality.
A buffer of dimensions ArrayDimension structures which will be filled in to fully describe the layout of the array in memory.

### `pDimensions`

A buffer of dimensions ArrayDimension structures which will be filled in to fully describe the layout of the array in memory.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostType> spType; /* get a type for some array (see FindTypeByName) */

ArrayDimension adim;
if (SUCCEEDED(spType->GetArrayDimensions(1, &adim)))
{
    // adim indicates information about the dimension.  For C/C++, length is
    // the largely relevant field.  C/C++ arrays are always zero based.  The
    // stride field would indicate the size of the array element type.
}
```

## See also

[IDebugHostType interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype)