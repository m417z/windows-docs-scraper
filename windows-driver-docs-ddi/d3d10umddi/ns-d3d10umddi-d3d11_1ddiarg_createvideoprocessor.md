# D3D11_1DDIARG_CREATEVIDEOPROCESSOR structure

## Description

Specifies the attributes of a video processor object.

## Members

### `hVideoProcessorEnum`

A handle to a video processor enumeration object that was created through a call to the [CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum) function.

### `RateConversionCapsIndex`

Specifies the frame-rate conversion capabilities for the video processor. The value is a zero-based index that corresponds to the *RateConversionIndex* parameter of the [GetVideoProcessorRateConversionCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorrateconversioncaps) method.

## See also

[CreateVideoProcessorEnum](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_createvideoprocessorenum)

[GetVideoProcessorRateConversionCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_getvideoprocessorrateconversioncaps)