## Description

The **D3D12DDI_DEVICE_FUNCS_VIDEO_0082_0** structure contains device driver functions for core features in video, used in D3D12DDI_FEATURE_VERSION_VIDEO_0083_0.

## Members

### `pfnGetCaps`

Pointer to a [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) callback function.

### `pfnCalcPrivateVideoDecoderSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideodecodersize_0072) callback function.

### `pfnCreateVideoDecoder`

Pointer to a [**PFND3D12DDI_CREATEVIDEODECODER_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideodecoder_0072) callback function.

### `pfnDestroyVideoDecoder`

Pointer to a [**PFND3D12DDI_DESTROYVIDEODECODER_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideodecoder_0021) callback function.

### `pfnCalcPrivateVideoDecoderHeapSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideodecoderheapsize_0072) callback function.

### `pfnCreateVideoDecoderHeap`

Pointer to a [**PFND3D12DDI_CREATEVIDEODECODERHEAP_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideodecoderheap_0072) callback function.

### `pfnDestroyVideoDecoderHeap`

Pointer to a [**PFND3D12DDI_DESTROYVIDEODECODERHEAP_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideodecoderheap_0032) callback function.

### `pfnCalcPrivateVideoProcessorSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoprocessorsize_0072) callback function.

### `pfnCreateVideoProcessor`

Pointer to a [**PFND3D12DDI_CREATEVIDEOPROCESSOR_0072**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoprocessor_0072) callback function.

### `pfnDestroyVideoProcessor`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOPROCESSOR_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideoprocessor_0021) callback function.

### `pfnCalcPrivateVideoMotionEstimatorSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOMOTIONESTIMATORSIZE_0060**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideomotionestimatorsize_0060) callback function.

### `pfnCreateVideoMotionEstimator`

Pointer to a [**PFND3D12DDI_CREATEVIDEOMOTIONESTIMATOR_0060**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideomotionestimator_0060) callback function.

### `pfnDestroyVideoMotionEstimator`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOMOTIONESTIMATOR_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideomotionestimator_0053) callback function.

### `pfnCalcPrivateVideoMotionVectorHeapSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOMOTIONVECTORHEAPSIZE_0060**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideomotionvectorheapsize_0060) callback function.

### `pfnCreateVideoMotionVectorHeap`

Pointer to a [**PFND3D12DDI_CREATEVIDEOMOTIONVECTORHEAP_0060**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideomotionvectorheap_0060) callback function.

### `pfnDestroyVideoMotionVectorHeap`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOMOTIONVECTORHEAP_0053**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideomotionvectorheap_0053) callback function.

### `pfnCalcPrivateVideoExtensionCommandSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOEXTENSIONCOMMANDSIZE_0061**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoextensioncommandsize_0061) callback function.

### `pfnCreateVideoExtensionCommand`

Pointer to a [**PFND3D12DDI_CREATEVIDEOEXTENSIONCOMMAND_0063**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoextensioncommand_0063) callback function.

### `pfnDestroyVideoExtensionCommand`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOEXTENSIONCOMMAND_0063**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideoextensioncommand_0063) callback function.

### `pfnExecuteDeviceVideoExtensionCommand`

Pointer to a [**PFND3D12DDI_EXECUTEDEVICEVIDEOEXTENSIONCOMMAND_0076**]() callback function.

### `pfnCalcPrivateVideoEncoderSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOENCODERSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencodersize_0082_0) callback function.

### `pfnCreateVideoEncoder`

Pointer to a [**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0) callback function.

### `pfnDestroyVideoEncoder`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOENCODER_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideoencoder_0080) callback function.

### `pfnCalcPrivateVideoEncoderHeapSize`

Pointer to a [**PFND3D12DDI_CALCPRIVATEVIDEOENCODERHEAPSIZE_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencoderheapsize_0080_2) callback function.

### `pfnCreateVideoEncoderHeap`

Pointer to a [**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2) callback function.

### `pfnDestroyVideoEncoderHeap`

Pointer to a [**PFND3D12DDI_DESTROYVIDEOENCODERHEAP_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_destroyvideoencoderheap_0080) callback function.

## Remarks

A client driver's [**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable) callback function retrieves the **D3D12DDI_DEVICE_FUNCS_VIDEO_0082_0** structure.

## See also

[**PFND3D12DDI_FILLDDITTABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_fillddittable)