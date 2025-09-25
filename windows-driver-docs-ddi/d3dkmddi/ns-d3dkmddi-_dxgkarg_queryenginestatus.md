# _DXGKARG_QUERYENGINESTATUS structure

## Description

Used in a call to the [DxgkDdiQueryEngineStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus) function to specify a node within an active physical adapter (engine) that is to be queried for its progress.

## Members

### `NodeOrdinal` [in]

An index of a node within the physical adapter defined by the **EngineOrdinal** member that is being queried in a call to [DxgkDdiQueryEngineStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus).

### `EngineOrdinal` [in]

An index that defines the physical adapter in a linked display adapter (LDA) configuration that the node defined by **NodeOrdinal** belongs to.

### `EngineStatus` [out]

The progress, of type [DXGK_ENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_enginestatus), of the node and physical adapter that are specified by the **NodeOrdinal** and **EngineOrdinal** members.

## Remarks

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[DXGK_ENGINESTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_enginestatus)

[DxgkDdiQueryEngineStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus)