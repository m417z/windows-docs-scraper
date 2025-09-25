## Description

**D3D12DDI_WORK_GRAPH_MEMORY_REQUIREMENTS_0108** is the structure in which the user-mode driver's [**pfnGetWorkGraphMemoryRequirements**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_work_graph_memory_requirements_0108) function returns work graph memory requirements.

## Members

### `MinSizeInBytes`

[out] The minimum number of bytes the driver needs for backing memory.

### `MaxSizeInBytes`

[out] The maximum number of bytes the driver needs for backing memory.

### `SizeGranularityInBytes`

[out] Multiple to use to determine other sizes that the driver can use. Sizes that are larger than **MinSizeInBytes** are larger by a multiple of **SizeGranularityInBytes**. The application can provide sizes for backing memory that are larger than **MinSizeInBytes** plus an integer multiple of **SizeGranularityInBytes**, or larger than **MaxSizeInBytes**, but it simply wastes memory as the driver won't touch memory beyond the size range and granularity specifications here.

## Remarks

The minimum can be reported as zero if the system doesn't need any backing memory for the graph. If the minimum is reported as zero, the maximum might also be reported as zero unless the system can use backing store if the app wants but can also handle being given none. When zero is reported as a valid size, application can pass null for the backing memory in SetProgram().

For more information, see [Work graphs](https://learn.microsoft.com/windows-hardware/drivers/display/work-graphs).

## See also

[**PFND3D12DDI_GET_WORK_GRAPH_MEMORY_REQUIREMENTS_0108**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_work_graph_memory_requirements_0108)