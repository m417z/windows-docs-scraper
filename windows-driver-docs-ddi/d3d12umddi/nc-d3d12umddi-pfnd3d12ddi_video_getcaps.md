# PFND3D12DDI_VIDEO_GETCAPS callback function

## Description

The D3D runtime calls a client driver's **PFND3D12DDI_VIDEO_GETCAPS** callback function to query for video-related support provided by the driver for a specified type.

## Parameters

### `hDrvDevice` [in]

The handle of a device.

### `pArgs` [in, out]

Pointer to a caller-allocated [**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020) structure used to request a video-specific capability.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following table provides a few examples of the meaning/values of **pData** and **DataSize** for various **D3D12DDICAPS_TYPE_VIDEO_0020** values. Note that **pInfo** points to NULL in all of these examples, so is not shown in the table.

| D3D12DDICAPS_TYPE_*XXX* | pData | DataSize |
| ----------------------- | ----- | -------- |
| *VIDEO_0020_DECODE_SUPPORT* | D3D12DDI_VIDEO_DECODE_SUPPORT_DATA_0020 * | sizeof(D3D12DDI_VIDEO_DECODE_SUPPORT_DATA_0020) |
| *VIDEO_0020_DECODE_PROFILES* | D3D12DDI_VIDEO_DECODE_PROFILES_DATA_0020 * | sizeof(D3D12DDI_VIDEO_DECODE_PROFILES_DATA_0020) |
| *VIDEO_0020_PROCESS_SUPPORT* | D3D12DDI_VIDEO_PROCESS_SUPPORT_DATA_0032 * | sizeof(D3D12DDI_VIDEO_PROCESS_SUPPORT_DATA_0032) |
| *VIDEO_0032_DECODER_HEAP_SIZE* | D3D12DDI_VIDEO_DECODER_HEAP_SIZE_DATA_0072 * | sizeof(D3D12DDI_VIDEO_DECODER_HEAP_SIZE_DATA_0072) |
| *VIDEO_0053_MOTION_ESTIMATOR* | D3D12DDI_VIDEO_MOTION_ESTIMATOR_DATA_0053 * | sizeof(D3D12DDI_VIDEO_MOTION_ESTIMATOR_DATA_0053) |
| *VIDEO_0080_ENCODER_CODEC* | D3D12DDICAPS_VIDEO_ENCODER_CODEC_DATA_0080 | sizeof(D3D12DDICAPS_VIDEO_ENCODER_CODEC_DATA_0080) |

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)

[**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable)