# D3D12_FEATURE_DATA_D3D12_OPTIONS1 structure

## Description

Describes the level of support for HLSL 6.0 wave operations.

## Members

### `WaveOps`

True if the driver supports HLSL 6.0 wave operations.

### `WaveLaneCountMin`

Specifies the baseline number of lanes in the SIMD wave that this implementation can support. This term is sometimes known as "wavefront size" or "warp width". Currently apps should rely only on this minimum value for sizing workloads.

### `WaveLaneCountMax`

Specifies the maximum number of lanes in the SIMD wave that this implementation can support.

### `TotalLaneCount`

Specifies the total number of SIMD lanes on the hardware.

### `ExpandedComputeResourceStates`

Indicates transitions are possible in and out of the CBV, and indirect argument states, on compute command lists. If [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) succeeds this value will always be true.

### `Int64ShaderOps`

Indicates that 64bit integer operations are supported.

## Remarks

A "lane" is single thread of execution. The shader models before version 6.0 expose only one of these at the language level, leaving expansion to parallel SIMD processing entirely up to the implementation.

A "wave" is set of lanes (threads) executed simultaneously in the processor. No explicit barriers are required to guarantee that they execute in parallel. Similar concepts include "warp" and "wavefront".

This structure is used with the D3D12_FEATURE_D3D12_OPTIONS1 member of [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)