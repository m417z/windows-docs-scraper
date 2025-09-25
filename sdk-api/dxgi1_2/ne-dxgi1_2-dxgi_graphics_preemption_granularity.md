# DXGI_GRAPHICS_PREEMPTION_GRANULARITY enumeration

## Description

Identifies the granularity at which the graphics processing unit (GPU) can be preempted from performing its current graphics rendering task.

## Constants

### `DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY:0`

Indicates the preemption granularity as a DMA buffer.

### `DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY:1`

Indicates the preemption granularity as a graphics primitive. A primitive is a section in a DMA buffer and can be a group of triangles.

### `DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY:2`

Indicates the preemption granularity as a triangle. A triangle is a part of a primitive.

### `DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY:3`

Indicates the preemption granularity as a pixel. A pixel is a part of a triangle.

### `DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY:4`

Indicates the preemption granularity as a graphics instruction. A graphics instruction operates on a pixel.

## Remarks

You call the [IDXGIAdapter2::GetDesc2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiadapter2-getdesc2) method to retrieve the granularity level at which the GPU can be preempted from performing its current graphics rendering task. The operating system specifies the graphics granularity level in the **GraphicsPreemptionGranularity** member of the [DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2) structure.

The following figure shows granularity of graphics rendering tasks.

![Graphics Rendering Granularity](https://learn.microsoft.com/windows/win32/api/dxgi1_2/images/Graphics_Preempt.png)

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2)