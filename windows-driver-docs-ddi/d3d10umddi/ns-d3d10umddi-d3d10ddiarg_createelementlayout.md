# D3D10DDIARG_CREATEELEMENTLAYOUT structure

## Description

The D3D10DDIARG_CREATEELEMENTLAYOUT structure describes the element layout to create.

## Members

### `pVertexElements` [in]

An array of [D3D10DDIARG_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_input_element_desc) structures that describes each element in the element layout.

### `NumElements` [in]

The number of elements in that array that the **pVertexElements** member specifies.

## See also

[CalcPrivateElementLayoutSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivateelementlayoutsize)

[CreateElementLayout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createelementlayout)

[D3D10DDIARG_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_input_element_desc)