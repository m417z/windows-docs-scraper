# D3D11_FEATURE_DATA_MARKER_SUPPORT structure

## Description

**Note** This structure is supported by the Direct3D 11.2 runtime, which is available on Windows 8.1 and later operating systems.

Describes whether a GPU profiling technique is supported.

## Members

### `Profile`

Specifies whether the hardware and driver support a GPU profiling technique that can be used with development tools. The runtime sets this member to **TRUE** if the hardware and driver support data marking.

## Remarks

If the Direct3D API is the Direct3D 11.2 runtime and can support 11.2 features, [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) for **D3D11_FEATURE_MARKER_SUPPORT** will return a SUCCESS code when valid parameters are passed. The **Profile** member of **D3D11_FEATURE_DATA_MARKER_SUPPORT** will be set to **TRUE** or **FALSE**.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)