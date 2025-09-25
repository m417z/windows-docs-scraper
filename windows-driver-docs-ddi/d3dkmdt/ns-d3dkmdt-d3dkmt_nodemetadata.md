## Description

The **D3DKMT_NODEMETADATA** structure describes the metadata for a node.

## Members

### `NodeOrdinalAndAdapterIndex`

[in] Identifies the node ordinal and adapter index. The high word is the physical adapter index, and the low word is the node ordinal.

### `NodeData`

[out] A [**DXGK_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata) structure in which the display miniport driver writes the metadata for the node.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[**DXGK_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata)