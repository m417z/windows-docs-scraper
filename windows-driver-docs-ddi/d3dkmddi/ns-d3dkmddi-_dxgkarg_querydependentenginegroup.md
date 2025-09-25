# DXGKARG_QUERYDEPENDENTENGINEGROUP structure

## Description

Describes all nodes on the physical display adapter (engine) that are to be queried when the display port driver's GPU scheduler calls the [**DxgkDdiQueryDependentEngineGroup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup) function to query node dependencies.

## Members

### `NodeOrdinal` [in]

An index of a node within the physical adapter defined by the **EngineOrdinal** member that is being queried in a call to [**DxgkDdiQueryDependentEngineGroup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup).

### `EngineOrdinal` [in]

An index that defines the physical adapter in a linked display adapter (LDA) configuration that the node defined by **NodeOrdinal** belongs to.

### `DependentNodeOrdinalMask` [out]

The bitmask that describes all dependent nodes that will be affected by a reset operation.

## Remarks

The index value **EngineOrdinal** is assumed to be identical for all dependent nodes.

See Remarks of [**DxgkDdiQueryDependentEngineGroup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup) for a discussion of how to compute the bitmask in the **DependentNodeOrdinalMask** member.

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[**DxgkDdiQueryDependentEngineGroup**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup)

[**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine)