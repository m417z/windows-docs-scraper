## Description

Retrieve a single part from a DXIL container.

## Parameters

### `pShader`

The shader to retrieve the part from.

### `DxcPart`

The part to retrieve; for example, **DXC_PART_ROOT_SIGNATURE**.

### `ppPartData`

The address of the pointer that receives a pointer to the part. The returned pointer points inside the buffer passed in *pShader*.

### `pPartSizeInBytes`

The address of the pointer that receives the size of the part.

## Return value

## Remarks

## See also