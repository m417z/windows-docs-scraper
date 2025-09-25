# D3D12DDICAPS_TYPE enumeration

## Description

**D3D12DDICAPS_TYPE** specifies a capability type in [**D3D12DDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps).

## Constants

### `D3D12DDICAPS_TYPE_TEXTURE_LAYOUT`

Texture layout. Deprecated. Use D3D12DDICAPS_TYPE_0022_TEXTURE_LAYOUT instead.

### `D3D12DDICAPS_TYPE_SWIZZLE_PATTERN`

Swizzle pattern. Deprecated. Use D3D12DDICAPS_TYPE_0022_SWIZZLE_PATTERN instead.

### `D3D12DDICAPS_TYPE_MEMORY_ARCHITECTURE`

Memory architecture.

### `D3D12DDICAPS_TYPE_TEXTURE_LAYOUT_SETS`

Texture layout sets.

### `D3D12DDICAPS_TYPE_SHADER`

Shader.

### `D3D12DDICAPS_TYPE_ARCHITECTURE_INFO`

Architecture information.

### `D3D12DDICAPS_TYPE_D3D12_OPTIONS`

Options for D3D12.

### `D3D12DDICAPS_TYPE_3DPIPELINESUPPORT`

The driver provides 3D pipeline support. The driver reports the [**D3D12DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_3dpipelinelevel) value that represents the maximum pipeline level that it supports. Valid returnable feature levels are 12.1 and earlier. The **3DPIPELINESUPPORT1** value is used to query for any feature level, including 12.2 and later. See Remarks.

### `D3D12DDICAPS_TYPE_GPUVA_CAPS`

The driver supports GPU video acceleration capabilities.

### `D3D12DDICAPS_TYPE_TEXTURE_LAYOUT1`

Texture layout. Deprecated. Use D3D12DDICAPS_TYPE_0022_TEXTURE_LAYOUT instead.

### `D3D12DDICAPS_TYPE_0011_SHADER_MODELS`

Shader models.

### `D3D12DDICAPS_TYPE_OPTIONS1_0103`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0103**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_options_data_0103) structure.

### `D3D12DDICAPS_TYPE_0030_PROTECTED_RESOURCE_SESSION_SUPPORT`

Protected resource session support.

### `D3D12DDICAPS_TYPE_0030_CRYPTO_SESSION_SUPPORT`

Crypto session support. Deprecated. See D3D12DDICAPS_TYPE_VIDEO_0032_CRYPTO_SESSION_SUPPORT in to [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

### `D3D12DDICAPS_TYPE_0022_CPU_PAGE_TABLE_FALSE_POSITIVES`

CPU page table false positives.

### `D3D12DDICAPS_TYPE_0022_TEXTURE_LAYOUT`

Texture layout.

### `D3D12DDICAPS_TYPE_0022_SWIZZLE_PATTERN`

Swizzle pattern.

### `D3D12DDICAPS_TYPE_0023_UMD_BASED_COMMAND_QUEUE_PRIORITY`

User mode driver-based command queue priority.

### `D3D12DDICAPS_TYPE_0030_CONTENT_PROTECTION_SYSTEM_COUNT`

Content protection system count. Deprecated. See D3D12DDICAPS_TYPE_VIDEO_0032_CONTENT_PROTECTION_SYSTEM_COUNT in to [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

### `D3D12DDICAPS_TYPE_0030_CONTENT_PROTECTION_SYSTEM_SUPPORT`

Content protection system support. Deprecated. See D3D12DDICAPS_TYPE_VIDEO_0032_CONTENT_PROTECTION_SYSTEM_SUPPORT in to [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

### `D3D12DDICAPS_TYPE_0030_CRYPTO_SESSION_TRANSFORM_SUPPORT`

Crypto transform support. Deprecated. See D3D12DDICAPS_TYPE_VIDEO_0032_CRYPTO_SESSION_TRANSFORM_SUPPORT in to [D3D12DDICAPS_TYPE_VIDEO_0020](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020).

### `D3D12DDICAPS_TYPE_0033_ADAPTER_COMPUTE_ONLY`

Adapter compute only.

### `D3D12DDICAPS_TYPE_0050_HARDWARE_SCHEDULING_CAPS`

Hardware scheduling capabilities.

### `D3D12DDICAPS_TYPE_QUERY_META_COMMAND_CAPS_0061`

Query meta-command capabilities.

### `D3D12DDICAPS_TYPE_EXECUTECOMMANDLISTS_PARALLELISM`

Execute command lists in parallel.

### `D3D12DDICAPS_TYPE_SAMPLER_FEEDBACK_0073`

Supports sampler feedback. See the [Sampler Feedback Specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html) for more information.

### `D3D12DDICAPS_TYPE_0073_SUPPORT_BATCHED_MARKERS`

Indicates whether UMD supports batched markers.

### `D3D12DDICAPS_TYPE_0074_PROTECTED_RESOURCE_SESSION_TYPE_COUNT`

Supports protected resource session type count. Starting with D3D12DDI_FEATURE_VERSION_CONTENT_PROTECTION_RESOURCES_0074, this query is made if the driver reports D3D12DDI_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_SUPPORTED via D3D12DDICAPS_TYPE_PROTECTED_RESOURCE_SESSION_SUPPORT. The driver must report at least 1 GUID for D3D12DDI_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED. See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

### `D3D12DDICAPS_TYPE_0074_PROTECTED_RESOURCE_SESSION_TYPES`

Supports protected resource session types. Starting with D3D12DDI_FEATURE_VERSION_CONTENT_PROTECTION_RESOURCES_0074, this query is made if the driver reports D3D12DDI_PROTECTED_RESOURCE_SESSION_SUPPORT_FLAG_SUPPORTED via D3D12DDICAPS_TYPE_PROTECTED_RESOURCE_SESSION_SUPPORT. The driver must report D3D12DDI_PROTECTED_RESOURCES_SESSION_HARDWARE_PROTECTED. Allowed GUIDS are controlled via an allow list and additional GUIDS require approval from Microsoft. See the [Protected Resources Specification](https://microsoft.github.io/DirectX-Specs/d3d/ProtectedResources.html) for more information.

### `D3D12DDICAPS_TYPE_0081_3DPIPELINESUPPORT1`

Support for 3D pipeline; [**pData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) points to a [**D3D12DDI_3DPIPELINESUPPORT1_DATA_0081**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_3dpipelinesupport1_data_0081) structure. The driver reports the [**D3D12DDI_3DPIPELINELEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_3dpipelinelevel) value that represents the maximum feature level that it supports in the **MaximumDriverSupportedFeatureLevel** field. See Remarks.

### `D3D12DDICAPS_TYPE_0103_WAVE_MMA`

Queries the device's support for wave-level matrix multiply accumulate (MMA) operations, with the data returned in a [**D3D12DDI_WAVE_MMA_DATA_0103**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_wave_mma_data_0103) structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0090`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0090**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_options_data_0090) structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0091`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0091**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_options_data_0091) structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0093`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0093**] structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0098`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0098**] structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0101`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0101**] structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0102`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0102**] structure.

### `D3D12DDI_FEATURE_D3D12_PREDICATION_106`

Queries the driver's support for predication.

### `D3D12DDI_FEATURE_PLACED_RESOURCE_SUPPORT_INFO_106`

Queries the driver's support for placed resource support information.

### `D3D12DDI_FEATURE_HARDWARE_COPY_106`

Queries the device's support for hardware copy operations.

### `D3D12DDICAPS_TYPE_OPTIONS_0109`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0109**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_options_data_0109) structure.

### `D3D12DDICAPS_TYPE_OPTIONS_0110`

Queries the driver's support for capabilities in the [**D3D12DDI_OPTIONS_DATA_0110**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_options_data_0110) structure.

### `D3D12DDICAPS_TYPE_SHADER_MODEL_6_8_OPTIONS_0110`

Queries the device's support for Shader Model 6.8 options.

## Remarks

The Direct3D runtime specifies a **D3DDDICAPS_TYPE_*XXX*** in [**D3D12DDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps) when it calls a driver's [**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps) callback function.

When determining 3D pipeline support:

* Versions of Direct3D built into the operating system at or before Windows 10, version 20H2 use **3DPIPELINESUPPORT**.
* Versions of Direct3D built into Windows Server 2022 operating system, or organized as a re-distributable, use **3DPIPELINESUPPORT1**, and fall back to 3DPIPELINESUPPORT if it fails.

## See also

[**D3D12DDIARG_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)