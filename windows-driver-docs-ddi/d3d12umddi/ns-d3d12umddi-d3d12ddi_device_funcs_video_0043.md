# D3D12DDI_DEVICE_FUNCS_VIDEO_0043 structure

## Description

The device functions of video.

## Members

### `pfnGetCaps`

Get capabilities. See [PFND3D12DDI_VIDEO_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps).

### `pfnCalcPrivateVideoDecoderSize`

Calculates the private video decoder size. See [PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideodecodersize_0032).

### `pfnCreateVideoDecoder`

Creates a video decoder. See [PFND3D12DDI_CREATEVIDEODECODER_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideodecoder_0032).

### `pfnDestroyVideoDecoder`

Destroys the video decoder. See [PFND3D12DDI_DESTROYVIDEODECODER_0021](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideodecoder_0021).

### `pfnCalcPrivateVideoDecoderHeapSize`

Calculates the private video decoder heap size. See [PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0033](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideodecoderheapsize_0033).

### `pfnCreateVideoDecoderHeap`

Creates the video decoder heap. See [PFND3D12DDI_CREATEVIDEODECODERHEAP_0033](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideodecoderheap_0033).

### `pfnDestroyVideoDecoderHeap`

Destroys the video decoder heap. See [PFND3D12DDI_DESTROYVIDEODECODERHEAP_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideodecoderheap_0032).

### `pfnCalcPrivateVideoProcessorSize`

Calculates the private video processor size. See [PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoprocessorsize_0043).

### `pfnCreateVideoProcessor`

Creates the video processor. See [PFND3D12DDI_CREATEVIDEOPROCESSOR_0032](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoprocessor_0043).

### `pfnDestroyVideoProcessor`

Destroys the video processor. See [PFND3D12DDI_DESTROYVIDEOPROCESSOR_0021](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideoprocessor_0021).

## Syntax

```cpp
typedef struct D3D12DDI_DEVICE_FUNCS_VIDEO_0043
{
    PFND3D12DDI_VIDEO_GETCAPS                                           pfnGetCaps;
    PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0032                        pfnCalcPrivateVideoDecoderSize;
    PFND3D12DDI_CREATEVIDEODECODER_0032                                 pfnCreateVideoDecoder;
    PFND3D12DDI_DESTROYVIDEODECODER_0021                                pfnDestroyVideoDecoder;
    PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0033                    pfnCalcPrivateVideoDecoderHeapSize;
    PFND3D12DDI_CREATEVIDEODECODERHEAP_0033                             pfnCreateVideoDecoderHeap;
    PFND3D12DDI_DESTROYVIDEODECODERHEAP_0032                            pfnDestroyVideoDecoderHeap;
    PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043                      pfnCalcPrivateVideoProcessorSize;
    PFND3D12DDI_CREATEVIDEOPROCESSOR_0043                               pfnCreateVideoProcessor;
    PFND3D12DDI_DESTROYVIDEOPROCESSOR_0021                              pfnDestroyVideoProcessor;
} D3D12DDI_DEVICE_FUNCS_VIDEO_0043;
```