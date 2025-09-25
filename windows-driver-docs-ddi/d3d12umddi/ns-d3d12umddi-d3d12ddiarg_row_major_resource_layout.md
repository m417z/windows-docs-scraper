## Description

The **D3D12DDIARG_ROW_MAJOR_RESOURCE_LAYOUT** structure describes the layout of a row-major resource.

## Members

### `RowPitch`

The length in bytes of the pitch, or width, of one row of the resource.

### `SlicePitch`

The distance in bytes from the beginning of one depth level to the next.
Slice pitch is only used for 3D texture data as it has no meaning for the other resource types.

## See also

[**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088)