# D3D12DDIARG_VIDEO_GETCAPS_0020 structure

## Description

The **D3D12DDIARG_VIDEO_GETCAPS_0020** structure is used to get a specified type of video-related capability/support during a call to a client driver's [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) function.

## Members

### `Type`

Pointer to a [**D3D12DDICAPS_TYPE_VIDEO_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) value that specifies the video-related capability type.

### `pInfo`

A pointer to a memory block that contains data that specifies the condition on which to retrieve the capabilities of the type that is specified by the **Type** member. Set this field to point to NULL to indicate no condition.

### `pData`

A pointer to a memory block that contains capabilities of the type that is specified by the **Type** member and possibly determined by the condition specified by the **pInfo** member.

### `DataSize`

The size, in bytes, of the memory block at **pData**.

## Remarks

See [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) for examples of the meaning/values of **pInfo**, **pData**, and **DataSize** for various [**D3D12DDICAPS_TYPE_VIDEO_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) types.

## See also

[**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps)