# D3D12DDI_RAYTRACING_SHADER_CONFIG_0054 structure

## Description

Describes the ray tracing shader configuration.

## Members

### `MaxPayloadSizeInBytes`

The maximum storage for scalars (counted as 4 bytes each) in ray payloads in ray tracing pipelines that contain this program.

### `MaxAttributeSizeInBytes`

The maximum number of scalars (counted as 4 bytes each) that can be used for attributes in pipelines that contain this shader.

## Remarks

A ray tracing pipeline needs one ray tracing shader configuration. If multiple shader configurations are present, such as one in each collection to enable independent driver compilation for each one, they must all match when combined into a ray tracing pipeline.

## See also