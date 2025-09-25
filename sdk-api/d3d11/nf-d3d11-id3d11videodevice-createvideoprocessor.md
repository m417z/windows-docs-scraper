# ID3D11VideoDevice::CreateVideoProcessor

## Description

Creates a video processor device for Microsoft Direct3D 11.

## Parameters

### `pEnum` [in]

A pointer to the [ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessorenumerator).

### `RateConversionIndex` [in]

Specifies the frame-rate conversion capabilities for the video processor. The value is a zero-based index that corresponds to the *TypeIndex* parameter of the [ID3D11VideoProcessorEnumerator::GetVideoProcessorRateConversionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorrateconversioncaps) method.

### `ppVideoProcessor` [out]

Receives a pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [ID3D11DeviceContext::ClearState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-clearstate) method does not affect the internal state of the video processor.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)