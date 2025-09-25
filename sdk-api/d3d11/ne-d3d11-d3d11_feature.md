## Description

Direct3D 11 feature options.

## Constants

### `D3D11_FEATURE_THREADING:0`

The driver supports [multithreading](https://learn.microsoft.com/windows/win32/direct3d11/overviews-direct3d-11-render-multi-thread-intro). To see an example of testing a driver for multithread support, see [How To: Check for Driver Support](https://learn.microsoft.com/windows/win32/direct3d11/overviews-direct3d-11-render-multi-thread-support). Refer to [D3D11_FEATURE_DATA_THREADING](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_threading).

### `D3D11_FEATURE_DOUBLES`

Supports the use of the double-precision shaders in HLSL. Refer to [D3D11_FEATURE_DATA_DOUBLES](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_doubles).

### `D3D11_FEATURE_FORMAT_SUPPORT`

Supports the formats in [D3D11_FORMAT_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_format_support). Refer to [D3D11_FEATURE_DATA_FORMAT_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_format_support).

### `D3D11_FEATURE_FORMAT_SUPPORT2`

Supports the formats in [D3D11_FORMAT_SUPPORT2](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_format_support2). Refer to [D3D11_FEATURE_DATA_FORMAT_SUPPORT2](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_format_support2).

### `D3D11_FEATURE_D3D10_X_HARDWARE_OPTIONS`

Supports compute shaders and raw and structured buffers. Refer to [D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d10_x_hardware_options).

### `D3D11_FEATURE_D3D11_OPTIONS`

Supports Direct3D 11.1 feature options. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FEATURE_ARCHITECTURE_INFO`

Supports specific adapter architecture. Refer to [D3D11_FEATURE_DATA_ARCHITECTURE_INFO](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_architecture_info).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FEATURE_D3D9_OPTIONS`

Supports Direct3D 9 feature options. Refer to [D3D11_FEATURE_DATA_D3D9_OPTIONS](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_options).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FEATURE_SHADER_MIN_PRECISION_SUPPORT`

Supports minimum precision of shaders. For more info about HLSL minimum precision, see [using HLSL minimum precision](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features). Refer to [D3D11_FEATURE_DATA_SHADER_MIN_PRECISION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_shader_min_precision_support).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FEATURE_D3D9_SHADOW_SUPPORT`

Supports Direct3D 9 shadowing feature. Refer to [D3D11_FEATURE_DATA_D3D9_SHADOW_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_shadow_support).

**Direct3D 11:** This value is not supported until Direct3D 11.1.

### `D3D11_FEATURE_D3D11_OPTIONS1`

Supports Direct3D 11.2 feature options. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1).

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT`

Supports Direct3D 11.2 instancing options. Refer to [D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_simple_instancing_support).

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FEATURE_MARKER_SUPPORT`

Supports Direct3D 11.2 marker options. Refer to [D3D11_FEATURE_DATA_MARKER_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_marker_support).

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FEATURE_D3D9_OPTIONS1`

Supports Direct3D 9 feature options, which includes the Direct3D 9 shadowing feature and instancing support. Refer to [D3D11_FEATURE_DATA_D3D9_OPTIONS1](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_options1).

**Direct3D 11:** This value is not supported until Direct3D 11.2.

### `D3D11_FEATURE_D3D11_OPTIONS2`

Supports Direct3D 11.3 conservative rasterization feature options. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS2](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options2).

**Direct3D 11:** This value is not supported until Direct3D 11.3.

### `D3D11_FEATURE_D3D11_OPTIONS3`

Supports Direct3D 11.4 conservative rasterization feature options. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS3](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options3).

**Direct3D 11:** This value is not supported until Direct3D 11.4.

### `D3D11_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT`

Supports GPU virtual addresses. Refer to [D3D11_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_gpu_virtual_address_support).

### `D3D11_FEATURE_D3D11_OPTIONS4`

Supports a single boolean for NV12 shared textures. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS4](https://learn.microsoft.com/windows/win32/api/d3d11_4/ns-d3d11_4-d3d11_feature_data_d3d11_options4).

**Direct3D 11:** This value is not supported until Direct3D 11.4.

### `D3D11_FEATURE_SHADER_CACHE`

Supports shader cache, described in [D3D11_FEATURE_DATA_SHADER_CACHE](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_shader_cache).

### `D3D11_FEATURE_D3D11_OPTIONS5`

Supports a [D3D11_SHARED_RESOURCE_TIER](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_shared_resource_tier) to indicate the level of support for shared resources in the current graphics driver. Refer to [D3D11_FEATURE_DATA_D3D11_OPTIONS5](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options5).

### `D3D11_FEATURE_DISPLAYABLE`

Supports displayable surfaces, described in [D3D11_FEATURE_DATA_DISPLAYABLE](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_displayable).

## Remarks

This enumeration is used when querying a driver about support for these features by calling [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport). Each value in this enumeration has a corresponding data structure that is required to be passed to the *pFeatureSupportData* parameter of **ID3D11Device::CheckFeatureSupport**.

## See also

[Core enumerations](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-d3d11-core-enums)