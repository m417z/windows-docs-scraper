## Description

Contains the supported shader model.

## Members

### `HighestShaderModel`

Specifies one member of [D3D_SHADER_MODEL](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d_shader_model) that indicates the maximum supported shader model.

## Remarks

Refer to the enumeration constant *D3D12_FEATURE_SHADER_MODEL* in the [D3D12_FEATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature).

When used with the [ID3D12Device::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) function, before calling the function initialize the *HighestShaderModel* field to the highest shader model that your application understands. After the function completes successfully, the *HighestShaderModel* field contains the highest shader model that is both supported by the device and no higher than the shader model passed in.

> [!NOTE]
> **ID3D12Device::CheckFeatureSupport** returns **E_INVALIDARG** if *HighestShaderModel* isn't known by the current runtime. For that reason, we recommend that you call this in a loop with decreasing shader models to determine the highest supported shader model. Alternatively, use the caps checking helper to simplify this; see the blog post [Introducing a New API for Checking Feature Support in Direct3D 12](https://devblogs.microsoft.com/directx/introducing-a-new-api-for-checking-feature-support-in-direct3d-12/).

## See also

* [Core structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)
* [D3D12_FEATURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_feature)