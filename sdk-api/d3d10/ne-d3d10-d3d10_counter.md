# D3D10_COUNTER enumeration

## Description

Performance counter types.

## Constants

### `D3D10_COUNTER_GPU_IDLE:0`

Percentage of the time that the GPU is idle.

### `D3D10_COUNTER_VERTEX_PROCESSING`

Percentage of the time that the GPU does vertex processing.

### `D3D10_COUNTER_GEOMETRY_PROCESSING`

Percentage of the time that the GPU does geometry processing.

### `D3D10_COUNTER_PIXEL_PROCESSING`

Percentage of the time that the GPU does pixel processing.

### `D3D10_COUNTER_OTHER_GPU_PROCESSING`

Percentage of the time that the GPU does other processing (not vertex, geometry, or pixel processing).

### `D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION`

Percentage of bandwidth used on a host adapter. Value returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) between 0.0 and 1.0 when using this counter.

### `D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION`

Percentage of bandwidth used by the local video memory. Value returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) between 0.0 and 1.0 when using this counter

### `D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION`

Percentage of throughput used for vertices. Value returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) between 0.0 and 1.0 when using this counter

### `D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION`

Percentage of throughput used for triangle setup. Value returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) between 0.0 and 1.0 when using this counter

### `D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION`

Percentage of throughput used for the fillrate. Value returned by [ID3D10Asynchronous::GetData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10asynchronous-getdata) between 0.0 and 1.0 when using this counter.

### `D3D10_COUNTER_VS_MEMORY_LIMITED`

Percentage of time that a vertex shader spends sampling resources.

### `D3D10_COUNTER_VS_COMPUTATION_LIMITED`

Percentage of time that a vertex shader spends doing computations.

### `D3D10_COUNTER_GS_MEMORY_LIMITED`

Percentage of time that a geometry shader spends sampling resources.

### `D3D10_COUNTER_GS_COMPUTATION_LIMITED`

Percentage of time that a geometry shader spends doing computations.

### `D3D10_COUNTER_PS_MEMORY_LIMITED`

Percentage of time that a pixel shader spends sampling resources.

### `D3D10_COUNTER_PS_COMPUTATION_LIMITED`

Percentage of time that a pixel shader spends doing computations.

### `D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE`

Percentage of vertex data that was read from the vertex cache. For example, if 6 vertices were added to the cache and 3 of them were read from the cache, then the hit rate would be 0.5.

### `D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE`

Percentage of texel data that was read from the vertex cache. For example, if 6 texels were added to the cache and 3 of them were read from the cache, then the hit rate would be 0.5.

### `D3D10_COUNTER_DEVICE_DEPENDENT_0:0x40000000`

Start of the device-dependent counters. See remarks.

## Remarks

In addition to these performance counters, independent hardware vendors may define their own set of performance counters for their devices. The enum values for these counters would start after D3D10_COUNTER_DEVICE_DEPENDENT_0 and would be defined by those hardware vendors.

A device can support one or more of these performance counters, but it is not required to support any of them.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)