## Description

Defines constants that specify options for working with resources.

## Constants

### `D3D12_RESOURCE_FLAG_NONE:0`

No options are specified.

### `D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET:0x1`

Allows a render target view to be created for the resource; and also enables the resource to transition into the state of [D3D12_RESOURCE_STATE_RENDER_TARGET](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states). Some adapter architectures allocate extra memory for textures with this flag to reduce the effective bandwidth during common rendering. This characteristic may not be beneficial for textures that are never rendered to, nor is it available for textures compressed with BC formats. Your application should avoid setting this flag when rendering will never occur.

The following restrictions and interactions apply:

* Either the texture format must support render target capabilities at the current feature level. Or, when the format is a typeless format, a format within the same typeless group must support render target capabilities at the current feature level.
* Can't be set in conjunction with textures that have [D3D12_TEXTURE_LAYOUT_ROW_MAJOR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) when [D3D12_FEATURE_DATA_D3D12_OPTIONS::CrossAdapterRowMajorTextureSupported](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) is `FALSE`, nor in conjunction with textures that have [D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) when [D3D12_FEATURE_DATA_D3D12_OPTIONS::StandardSwizzle64KBSupported](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) is `FALSE`.
* Can't be used with 4KB alignment, **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL**, nor usage with heaps that have [D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags).

### `D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL:0x2`

Allows a depth stencil view to be created for the resource, as well as enables the resource to transition into the state of [D3D12_RESOURCE_STATE_DEPTH_WRITE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) and/or **D3D12_RESOURCE_STATE_DEPTH_READ**. Most adapter architectures allocate extra memory for textures with this flag to reduce the effective bandwidth, and maximize optimizations for early depth-test. Your application should avoid setting this flag when depth operations will never occur.

The following restrictions and interactions apply:

* Either the texture format must support depth stencil capabilities at the current feature level. Or, when the format is a typeless format, a format within the same typeless group must support depth stencil capabilities at the current feature level.
* Can't be used with [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension), 4KB alignment, **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET**, **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS**, **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS**, [D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout), **D3D12_TEXTURE_LAYOUT_ROW_MAJOR**, nor used with heaps that have [D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags) or **D3D12_HEAP_FLAG_ALLOW_DISPLAY**.
* Precludes usage of [WriteToSubresource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource) and [ReadFromSubresource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12resource-readfromsubresource).
* Precludes GPU copying of a subregion. [CopyTextureRegion](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion) must copy a whole subresource to or from resources with this flag.

### `D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS:0x4`

Allows an unordered access view to be created for the resource, as well as enables the resource to transition into the state of [D3D12_RESOURCE_STATE_UNORDERED_ACCESS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states). Some adapter architectures must resort to less efficient texture layouts in order to provide this functionality. If a texture is rarely used for unordered access, then it might be worth having two textures around and copying between them. One texture would have this flag, while the other wouldn't. Your application should avoid setting this flag when unordered access operations will never occur.

The following restrictions and interactions apply:

* Either the texture format must support unordered access capabilities at the current feature level. Or, when the format is a typeless format, a format within the same typeless group must support unordered access capabilities at the current feature level.
* Can't be set in conjunction with textures that have [D3D12_TEXTURE_LAYOUT_ROW_MAJOR](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) when [D3D12_FEATURE_DATA_D3D12_OPTIONS::CrossAdapterRowMajorTextureSupported](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) is `FALSE`, nor in conjunction with textures that have [D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) when [D3D12_FEATURE_DATA_D3D12_OPTIONS::StandardSwizzle64KBSupported](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) is `FALSE`, nor when the feature level is less than 11.0.
* Can't be used with MSAA textures.

### `D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE:0x8`

Disallows a shader resource view from being created for the resource, as well as disables the resource from transitioning into the state of [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) or **D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE**. Some adapter architectures gain bandwidth capacity for depth stencil textures when shader resource views are precluded. If a texture is rarely used for shader resources, then it might be worth having two textures around and copying between them. One texture would have this flag, while the other wouldn't. Your application should set this flag when depth stencil textures will never be used from shader resource views.

The following restrictions and interactions apply:

* Must be used with **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL**.

### `D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER:0x10`

Allows the resource to be used for cross-adapter data, as well as those features enabled by **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS**. Cross-adapter resources commonly preclude techniques that reduce effective texture bandwidth during usage, and some adapter architectures might require different caching behavior. Your application should avoid setting this flag when the resource data will never be used with another adapter.

The following restrictions and interactions apply:

* Must be used with heaps that have [D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags).
* Can't be used with heaps that have [D3D12_HEAP_FLAG_ALLOW_DISPLAY](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags).

### `D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS:0x20`

Allows a resource to be simultaneously accessed by multiple different queues, devices, or processes (for example, allows a resource to be used with [ResourceBarrier](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resourcebarrier) transitions performed in more than one command list executing at the same time).

Simultaneous access allows multiple readers and one writer, as long as the writer doesn't concurrently modify the texels that other readers are accessing. Some adapter architectures can't leverage techniques to reduce effective texture bandwidth during usage.

However, your application should avoid setting this flag when multiple readers are not required during frequent, non-overlapping writes to textures. Use of this flag can compromise resource fences to perform waits, and prevent any compression being used with a resource.

The following restrictions and interactions apply:

* Can't be used with [D3D12_RESOURCE_DIMENSION_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_dimension); but buffers always have the properties represented by this flag.
* Can't be used with MSAA textures.
* Can't be used with **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL**.

### `D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY:0x40`

Specfies that this resource may be used only as a decode reference frame. It may be written to or read only by the video decode operation.

[D3D12_VIDEO_DECODE_TIER_1](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) and [D3D12_VIDEO_DECODE_TIER_2](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) may report [D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_REFERENCE_ONLY_ALLOCATIONS_REQUIRED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_configuration_flags) in the [D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_support) structure configuration flag. If that happens, then your application must allocate reference frames with the **D3D12_RESOURCE_FLAGS::D3D12_RESOURCE_FLAG_VIDEO_DECODE_REFERENCE_ONLY** resource flag.

[D3D12_VIDEO_DECODE_TIER_3](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) must not set the [D3D12_VIDEO_DECODE_CONFIGURATION_FLAG_REFERENCE_ONLY_ALLOCATIONS_REQUIRED]
(../d3d12video/ne-d3d12video-d3d12_video_decode_configuration_flags) configuration flag, and must not require the use of this resource flag.

### `D3D12_RESOURCE_FLAG_VIDEO_ENCODE_REFERENCE_ONLY:0x80`

Specfies that this resource may be used only as an encode reference frame. It may be written to or read only by the video encode operation.

### `D3D12_RESOURCE_FLAG_RAYTRACING_ACCELERATION_STRUCTURE:0x100`

Requires the DirectX 12 Agility SDK 1.608.0 or later. Indicates that a buffer is to be used as a raytracing acceleration structure. When using D3D12 Enhanced Barriers, this flag serves as a replacement for `D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE`, since buffers no longer have layouts/states.

## Remarks

This enum is used by the *Flags* member of the [D3D12_RESOURCE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_desc).

## See also

* [Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)