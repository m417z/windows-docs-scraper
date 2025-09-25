# D3D12DDI_RESOLVE_MODE enumeration

## Description

Specifies a Render Pass resolve operation in display driver development.

## Constants

### `D3D12DDI_RESOLVE_MODE_DECOMPRESS:0`

Resolves compressed source samples to their uncompressed values. When using this operation, the source and destination resources must have the same sample count, unlike the min, max, and average operations that require the destination to have a sample count of 1.

### `D3D12DDI_RESOLVE_MODE_MIN:1`

Resolves the source samples to their minimum value. It can be used with any render target or depth stencil format.

### `D3D12DDI_RESOLVE_MODE_MAX:2`

Resolves the source samples to their maximum value. It can be used with any render target or depth stencil format.

### `D3D12DDI_RESOLVE_MODE_AVERAGE:3`

Resolves the source samples to their average value. It can be used with any non-integer render target format, including the depth plane. It can't be used with integer render target formats, including the stencil plane.

### `D3D12DDI_RESOLVE_MODE_ENCODE_SAMPLER_FEEDBACK_0073:4`

Transcode sampler feedback maps to an application-usable format.

### `D3D12DDI_RESOLVE_MODE_DECODE_SAMPLER_FEEDBACK_0073:5`

Transcode sampler feedback maps from an application-usable format.