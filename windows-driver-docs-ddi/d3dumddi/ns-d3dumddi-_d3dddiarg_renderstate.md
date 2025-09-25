# _D3DDDIARG_RENDERSTATE structure

## Description

The D3DDDIARG_RENDERSTATE structure describes how to update a specific render state.

## Members

### `State` [in]

A D3DDDIRENDERSTATETYPE-typed value that indicates the render state to be updated. For a definition of each value, see the corresponding value of the [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype) enumeration type in the DirectX documentation.

### `Value` [in]

The value to which the driver should update the render state that is identified by the **State** member. For more information about values that can be updated for each render state, see the definition of the corresponding render state in the [D3DRENDERSTATETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d9types/ne-d3d9types-_d3drenderstatetype) enumeration type in the DirectX documentation.

## See also

[SetRenderState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setrenderstate)