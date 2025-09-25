# _D3DKMDT_COMPUTE_PREEMPTION_GRANULARITY enumeration

## Description

Specifies the capabilities for the preemption of graphic processing unit (GPU) compute shader operations that the display miniport driver supports.

## Constants

### `D3DKMDT_COMPUTE_PREEMPTION_NONE`

The driver does not support the preemption of GPU compute shader operations.

**Note** This value also specifies that the driver cannot stop currently running DMA buffers of a specified type and cannot prevent all pending DMA buffers in the hardware queue from running.

### `D3DKMDT_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY`

The driver cannot stop currently running DMA buffers of a specified type but can prevent all pending DMA buffers in the hardware queue from running.

### `D3DKMDT_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY`

The driver cannot stop currently executing compute shader commands that were dispatched from a thread group but can prevent all pending commands from being dispatched.

### `D3DKMDT_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY`

The driver cannot stop currently executing compute shader commands that were dispatched from a thread group but can prevent a thread group from dispatching other commands.

### `D3DKMDT_COMPUTE_PREEMPTION_THREAD_BOUNDARY`

The driver cannot stop currently executing compute shader commands that were dispatched from a thread in a thread group but can prevent a thread from dispatching other commands.

### `D3DKMDT_COMPUTE_PREEMPTION_SHADER_BOUNDARY`

The driver cannot stop currently running shader commands of a specified type but can prevent all shader commands in the hardware queue from running.

## Remarks

Starting with Windows 8, display miniport drivers need to specify the level of preemption granularity supported by the GPU when executing compute shader operations. Because engines on the same adapter may potentially support different preemption levels, the driver should report the coarsest granularity among all engines capable of executing a particular type of compute shader requests.

For example, if one engine supports the preemption of primitive level graphics requests, and another engine supports the preemption of triangle level graphics requests, the driver should report primitive level graphics preemption capability for that adapter.

## See also

[D3DKMDT_GRAPHICS_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_graphics_preemption_granularity)

[D3DKMDT_PREEMPTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_preemption_caps)