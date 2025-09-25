## Description

Data structure used to check for video motion estimator protected resource support capabilities on a given node index.

## Members

### `NodeIndex` [in]

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `SupportFlags` [out]

A [**D3D12DDI_VIDEO_PROTECTED_RESOURCE_SUPPORT_FLAGS_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_protected_resource_support_flags_0072) value in which to return the video motion estimator protected resource support level.

## Remarks

This structure is the data used when querying [**D3D12DDICAPS_TYPE_VIDEO_0072_MOTION_ESTIMATOR_PROTECTED_RESOURCES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) via [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps).

See the [D3D Video Protected Resource Support Specification](https://microsoft.github.io/DirectX-Specs/d3d/D3D12_Video_ProtectedResourceSupport.html) for more information.

## See also

[**D3D12DDI_VIDEO_PROTECTED_RESOURCE_SUPPORT_FLAGS_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_protected_resource_support_flags_0072)

[**D3D12DDICAPS_TYPE_VIDEO_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020)

[**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps)