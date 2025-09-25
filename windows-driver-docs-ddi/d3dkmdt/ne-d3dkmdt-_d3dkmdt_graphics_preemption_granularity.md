# _D3DKMDT_GRAPHICS_PREEMPTION_GRANULARITY enumeration

## Description

Specifies the capabilities for the preemption of graphic processing unit (GPU) graphics operations that the display miniport driver supports.

## Constants

### `D3DKMDT_GRAPHICS_PREEMPTION_NONE`

The driver does not support the preemption of GPU graphics operations.

**Note** This value also specifies that the driver cannot stop currently running DMA buffers of a specified type and cannot prevent all pending DMA buffers in the hardware queue from running.

### `D3DKMDT_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY`

The driver cannot stop currently running DMA buffers of a specified type but can prevent all pending DMA buffers in the hardware queue from running.

### `D3DKMDT_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY`

The driver cannot stop currently running primitive buffers of a specified type but can prevent all pending primitive buffers in the hardware queue from running.

### `D3DKMDT_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY`

The driver cannot stop currently running triangle buffers of a specified type but can prevent all pending triangle buffers in the hardware queue from running.

### `D3DKMDT_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY`

The driver cannot stop currently running pixel buffers of a specified type but can prevent all pending pixel buffers in the hardware queue from running.

### `D3DKMDT_GRAPHICS_PREEMPTION_SHADER_BOUNDARY`

The driver cannot stop currently running shader instruction buffers of a specified type but can prevent all pending shader instruction buffers in the hardware queue from running.

## Remarks

Starting with Windows 8, display miniport drivers need to specify the level of preemption granularity supported by the GPU when executing graphics operations. Because engines on the same adapter may potentially support different preemption levels, the driver should report the coarsest granularity among all engines capable of executing a particular type of graphics request.

For example, if one engine supports the preemption of primitive level graphics requests, and another engine supports the preemption of triangle level graphics requests, the driver should report a capability of **D3DKMDT_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY** for the adapter.

## See also

[D3DKMDT_COMPUTE_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_compute_preemption_granularity)

[D3DKMDT_PREEMPTION_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_preemption_caps)