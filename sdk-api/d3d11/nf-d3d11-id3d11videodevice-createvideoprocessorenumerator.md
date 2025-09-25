# ID3D11VideoDevice::CreateVideoProcessorEnumerator

## Description

Enumerates the video processor capabilities of the driver.

## Parameters

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_PROCESSOR_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_content_desc) structure that describes the video content.

### `ppEnum` [out]

Receives a pointer to the [ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create the video processor device, pass the [ID3D11VideoProcessorEnumerator](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessorenumerator) pointer to the [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor) method.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)