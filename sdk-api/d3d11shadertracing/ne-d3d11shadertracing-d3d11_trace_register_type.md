# D3D11_TRACE_REGISTER_TYPE enumeration

## Description

Identifies a type of trace register.

## Constants

### `D3D11_TRACE_OUTPUT_NULL_REGISTER:0`

Output **NULL** register.

### `D3D11_TRACE_INPUT_REGISTER`

Input register.

### `D3D11_TRACE_INPUT_PRIMITIVE_ID_REGISTER`

Input primitive ID register.

### `D3D11_TRACE_IMMEDIATE_CONSTANT_BUFFER`

Immediate constant buffer.

### `D3D11_TRACE_TEMP_REGISTER`

Temporary register.

### `D3D11_TRACE_INDEXABLE_TEMP_REGISTER`

Temporary register that can be indexed.

### `D3D11_TRACE_OUTPUT_REGISTER`

Output register.

### `D3D11_TRACE_OUTPUT_DEPTH_REGISTER`

Output oDepth register.

### `D3D11_TRACE_CONSTANT_BUFFER`

Constant buffer.

### `D3D11_TRACE_IMMEDIATE32`

Immediate32 register.

### `D3D11_TRACE_SAMPLER`

Sampler.

### `D3D11_TRACE_RESOURCE`

Resource.

### `D3D11_TRACE_RASTERIZER`

Rasterizer.

### `D3D11_TRACE_OUTPUT_COVERAGE_MASK`

Output coverage mask.

### `D3D11_TRACE_STREAM`

Stream.

### `D3D11_TRACE_THIS_POINTER`

This pointer.

### `D3D11_TRACE_OUTPUT_CONTROL_POINT_ID_REGISTER`

Output control point ID register (this is actually an input; it defines the output that the thread controls).

### `D3D11_TRACE_INPUT_FORK_INSTANCE_ID_REGISTER`

Input fork instance ID register.

### `D3D11_TRACE_INPUT_JOIN_INSTANCE_ID_REGISTER`

Input join instance ID register.

### `D3D11_TRACE_INPUT_CONTROL_POINT_REGISTER`

Input control point register.

### `D3D11_TRACE_OUTPUT_CONTROL_POINT_REGISTER`

Output control point register.

### `D3D11_TRACE_INPUT_PATCH_CONSTANT_REGISTER`

Input patch constant register.

### `D3D11_TRACE_INPUT_DOMAIN_POINT_REGISTER`

Input domain point register.

### `D3D11_TRACE_UNORDERED_ACCESS_VIEW`

Unordered-access view.

### `D3D11_TRACE_THREAD_GROUP_SHARED_MEMORY`

Thread group shared memory.

### `D3D11_TRACE_INPUT_THREAD_ID_REGISTER`

Input thread ID register.

### `D3D11_TRACE_INPUT_THREAD_GROUP_ID_REGISTER`

Thread group ID register.

### `D3D11_TRACE_INPUT_THREAD_ID_IN_GROUP_REGISTER`

Input thread ID in-group register.

### `D3D11_TRACE_INPUT_COVERAGE_MASK_REGISTER`

Input coverage mask register.

### `D3D11_TRACE_INPUT_THREAD_ID_IN_GROUP_FLATTENED_REGISTER`

Input thread ID in-group flattened register.

### `D3D11_TRACE_INPUT_GS_INSTANCE_ID_REGISTER`

Input geometry shader (GS) instance ID register.

### `D3D11_TRACE_OUTPUT_DEPTH_GREATER_EQUAL_REGISTER`

Output oDepth greater than or equal register.

### `D3D11_TRACE_OUTPUT_DEPTH_LESS_EQUAL_REGISTER`

Output oDepth less than or equal register.

### `D3D11_TRACE_IMMEDIATE64`

Immediate64 register.

### `D3D11_TRACE_INPUT_CYCLE_COUNTER_REGISTER`

Cycle counter register.

### `D3D11_TRACE_INTERFACE_POINTER`

Interface pointer.

## Remarks

**D3D11_TRACE_REGISTER_TYPE** identifies the type of trace register in a [D3D11_TRACE_REGISTER](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ns-d3d11shadertracing-d3d11_trace_register) structure.

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-enums)