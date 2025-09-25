# D3D12_RAYTRACING_SHADER_CONFIG structure

## Description

A state subobject that represents a shader configuration.

## Members

### `MaxPayloadSizeInBytes`

The maximum storage for scalars (counted as 4 bytes each) in ray payloads in raytracing pipelines that contain this program.

### `MaxAttributeSizeInBytes`

The maximum number of scalars (counted as 4 bytes each) that can be used for attributes in pipelines that contain this shader. The value cannot exceed [D3D12_RAYTRACING_MAX_ATTRIBUTE_SIZE_IN_BYTES](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

## Remarks

A raytracing pipeline needs one raytracing shader configuration. If multiple shader configurations are present, such as one in each collection to enable independent driver compilation for each one, they must all match when combined into a raytracing pipeline.