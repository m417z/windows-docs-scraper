# D3D11_FEATURE_DATA_ARCHITECTURE_INFO structure

## Description

**Note** This structure is supported by the Direct3D 11.1 runtime, which is available on Windows 8 and later operating systems.

Describes information about Direct3D 11.1 adapter architecture.

## Members

### `TileBasedDeferredRenderer`

Specifies whether a rendering device batches rendering commands and performs multipass rendering into tiles or bins over a render area. Certain API usage patterns that are fine for TileBasedDefferredRenderers (TBDRs) can perform worse on non-TBDRs and vice versa. Applications that are careful about rendering can be friendly to both TBDR and non-TBDR architectures. **TRUE** if the rendering device batches rendering commands and **FALSE** otherwise.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)