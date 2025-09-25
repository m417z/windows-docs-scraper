## Description

The **D3D12DDIARG_CREATECOMMANDALLOCATOR** structure describes a [command allocator to create](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandallocator).

## Members

### `hDrvCommandAllocator`

Handle to associate with the command allocator. The driver must use this handle to identify the command allocator in subsequent calls to the driver.

### `Type`

A [**D3D12DDI_COMMAND_LIST_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_list_type) value that specifies the type of command list associated with the command allocator.

### `QueueFlags`

A [**D3D12DDI_COMMAND_QUEUE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_queue_flags) value that specifies the command queue flags associated with the command allocator.

## Remarks

This structure is passed to the [**pfnCreateCommandAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandallocator) function.

## See also

[**D3D12DDI_COMMAND_LIST_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_list_type)

[**D3D12DDI_COMMAND_QUEUE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_command_queue_flags)

[**pfnCreateCommandAllocator**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createcommandallocator)