## Description

The user-mode driver's **pfnGetWorkGraphMemoryRequirements** function gets the backing memory size requirements for a work graph.

## Parameters

### `unnamedParam1`

[in] A [**D3D12DDI_HSTATEOBJECT_0054**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_state_object_0054) handle to the state object for which the memory requirements are being queried.

### `pProgramName`

[in] Pointer to a string that contains the name of the work graph which to retrieve memory requirements.

### `pRequirements`

[out] Pointer to a [**D3D12DDI_WORK_GRAPH_MEMORY_REQUIREMENTS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_memory_requirements_0108) structure in which to return the backing memory size requirements for the work graph.

## Remarks

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**D3D12DDI_WORK_GRAPH_MEMORY_REQUIREMENTS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_work_graph_memory_requirements_0108)