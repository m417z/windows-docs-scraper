# IDebugHostType2::CreateArrayOf

## Description

For any given type, this returns a new [IDebugHostType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype) which is an array of this type.
The dimensions of the array must be supplied via the "dimensions" and "pDimensions" arguments.

## Parameters

### `dimensions`

The number of dimensions of the array type to create.

### `pDimensions`

A pointer to an array of ArrayDimension structures describing the structure of each dimension of the array type to create.

### `newType`

The newly created array type will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostType2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughosttype2)