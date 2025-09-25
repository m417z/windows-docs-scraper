# _D3DKMT_DEVICEPAGEFAULT_STATE structure

## Description

Contains information about the device page fault state.

## Members

### `FaultedPrimitiveAPISequenceNumber`

Identifies the draw that caused the page fault (or DXGK_PRIMITIVE_API_SEQUENCE_NUMBER_UNKNOWN if such information is not available), when per draw fence write is enabled.

### `FaultedPipelineStage`

Renders pipeline stage during which the fault was generated, or DXGK_RENDER_PIPELINE_STAGE_UNKNOWN if such information is not available.

### `FaultedBindTableEntry`

A bind table index of a resource being accessed at the time of the fault, or DXGK_BIND_TABLE_ENTRY_UNKNOWN if such information is not available.

### `PageFaultFlags`

Flags that specifies the nature of the fault.

### `FaultErrorCode`

A structure that contains the error code describing the fault.

### `FaultedVirtualAddress`

The virtual address of faulting resource, or D3DGPU_NULL if such information is not available.

## Remarks

## See also