# _DXGKARG_QUERYCURRENTFENCE structure

## Description

The DXGKARG_QUERYCURRENTFENCE structure describes the latest completed submission fence.

## Members

### `CurrentFence` [out]

The current fence data.

### `NodeOrdinal` [in]

The zero-based index of the node for the current fence.

### `EngineOrdinal` [in]

The zero-based index of the engine, within the node that **NodeOrdinal** specifies, for the current fence.

## See also

[DxgkDdiQueryCurrentFence](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querycurrentfence)