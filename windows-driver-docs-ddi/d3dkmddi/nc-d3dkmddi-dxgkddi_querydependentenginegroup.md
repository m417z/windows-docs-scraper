# DXGKDDI_QUERYDEPENDENTENGINEGROUP callback function

## Description

*Dxgkrnl*'s GPU scheduler calls **DxgkddiQuerydependentenginegroup** to query dependencies of nodes in a physical display adapter.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pQueryDependentEngineGroup`

[in/out] A [**DXGKARG_QUERYDEPENDENTENGINEGROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_querydependentenginegroup) structure in which KMD specifies all nodes affected by the reset operation.

## Return value

**DxgkddiQuerydependentenginegroup** must return **STATUS_SUCCESS**.

## Remarks

*Dxgkrnl*'s GPU scheduler calls this function to get a description of all physical adapters (engines) that will be affected by an engine reset request. It helps improve user experience on hardware architectures that have dependencies among multiple engines that can affect the reset process. Note that all affected nodes must have the same engine affinity value. (See the engine affinity discussion in [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).)

The GPU scheduler calls **DxgkDdiQueryDependentEngineGroup** every time it calls [**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine). The GPU scheduler waits 500 milliseconds for the display miniport driver to complete preemption of all dependent engines. For any engines that the driver can't complete a preemption, the GPU scheduler calls the **DxgkDdiResetEngine** function sequentially based upon the engine ordinal value.

Here is an example of how to compute the bitmask in the [**DXGKARG_QUERYDEPENDENTENGINEGROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_querydependentenginegroup).**DependentNodeOrdinalMask** member. If the original values of the **DXGKARG_QUERYDEPENDENTENGINEGROUP** structure's **NodeOrdinal** and **EngineOrdinal** members are 1 and 0, respectively, and additional nodes with identifiers 2 and 4 will also be reset when node 1 is reset, the driver should set **DependentNodeOrdinalMask** to 10110, or 0x16 in hexadecimal notation. The index value **EngineOrdinal** is assumed to be identical for all dependent nodes. The node being reset is included in the **DependentNodeOrdinalMask** bit mask.

This function should be made pageable, and it should always succeed.

The operating system guarantees that this function follows the first level synchronization mode as defined in [Threading and Synchronization First Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-first-level).

For more information, see [TDR changes in Windows 8](https://learn.microsoft.com/windows-hardware/drivers/display/tdr-changes-in-windows-8).

## See also

[**DXGKARG_CREATECONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createcontext)

[**DXGKARG_QUERYDEPENDENTENGINEGROUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_querydependentenginegroup)

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiResetEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine)