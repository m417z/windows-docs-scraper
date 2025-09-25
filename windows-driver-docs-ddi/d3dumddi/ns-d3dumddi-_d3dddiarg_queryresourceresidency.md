# _D3DDDIARG_QUERYRESOURCERESIDENCY structure

## Description

The D3DDDIARG_QUERYRESOURCERESIDENCY structure describes a list of resources on which residency is verified through the [QueryResourceResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresourceresidency) function.

## Members

### `pHandleList` [in]

An array of handles to resources whose residency is queried. **pHandleList** cannot be **NULL**. A resource can be an object, which is derived from the **IDirect3DResource9** interface for a texture, volume texture, cube texture, vertex buffer, index buffer, or surface. For more information about **IDirect3DResource9**, see the DirectX SDK documentation.

### `NumResources` [in]

The number of resources in the array in the **pHandleList** member. The range is from 1 through 0xFFFFF.

## See also

[QueryResourceResidency](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryresourceresidency)