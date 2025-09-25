## Description

The **D3D12DDI_COMMAND_LIST_TYPE** enumeration specifies the type of a command list.

## Constants

### `D3D12DDI_COMMAND_LIST_TYPE_DIRECT:0`

Specifies a command buffer that the GPU can execute directly. A direct command list doesn't inherit any GPU state, so all required state must be explicitly set within the command list.

### `D3D12DDI_COMMAND_LIST_TYPE_BUNDLE:1`

Specifies a command buffer that can only be executed directly via a direct command list. A bundle command list inherits the GPU state from the direct command list that executes it, except for the pipeline state object and primitive topology, which must be explicitly set within the bundle.

## See also

[**pfnCreateCommandAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandallocator)

[**pfnCreateCommandList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_create_command_list_0040)