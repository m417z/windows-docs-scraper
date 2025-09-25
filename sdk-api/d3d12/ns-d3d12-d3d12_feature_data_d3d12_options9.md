## Description

Indicates whether or not support exists for mesh shaders, values of *SV_RenderTargetArrayIndex* that are 8 or greater, typed resource 64-bit integer atomics, derivative and derivative-dependent texture sample operations, and the level of support for WaveMMA (wave_matrix) operations.

## Members

### `MeshShaderPipelineStatsSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not mesh shaders are supported. `true` if supported, otherwise `false`.

### `MeshShaderSupportsFullRangeRenderTargetArrayIndex`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not values of *SV_RenderTargetArrayIndex* that are 8 or greater are supported. `true` if supported, otherwise `false`.

### `AtomicInt64OnTypedResourceSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not typed resource 64-bit integer atomics are supported. `true` if supported, otherwise `false`.

### `AtomicInt64OnGroupSharedSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not 64-bit integer atomics are supported on `groupshared` variables. `true` if supported, otherwise `false`.

### `DerivativesInMeshAndAmplificationShadersSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not derivative and derivative-dependent texture sample operations are supported. `true` if supported, otherwise `false`.

### `WaveMMATier`

Type: \_Out\_ **[D3D12_WAVE_MMA_TIER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_wave_mma_tier)**

Indicates the level of support for WaveMMA (wave_matrix) operations.

## Remarks

## See also

* [Mesh shader spec](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html)