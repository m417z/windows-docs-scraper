# D3D12DDI_VIDEO_EXTENSION_COMMAND_SIZE_DATA_0063 structure

## Description

Queries the residency size information for a video extension command.

## Members

### `NodeIndex` [in]

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `CommandId` [in]

The unique identifier for the video extension command.

### `pCreationParameters` [in]

Pointer to the initialization parameters structure. Parameters for this structure must match the parameter enumeration for [D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_INITIALIZATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_extension_command_parameter_stage_0063).

### `CreationParametersSizeInBytes` [in]

The size of the initialization parameters structure in bytes.

### `MemoryPoolL0Size` [out]

Indicates the command size in L0. L0 is the “closest” memory to the GPU. For discrete adapters, this is discrete graphics memory. For integrated adapters, this is typically the system memory size.

### `MemoryPoolL1Size` [out]

Indicates the command size in L1. L1 is the “next closest” memory for GPU. For discrete adapters, this is system memory. Integrated adapters do not typically have L1 and report zero size here.

## Remarks

Drivers must support the existing pfnMakeResident and pfnEvict with the D3D12DDI_HVIDEOEXTENSIONCOMMAND.

## See also