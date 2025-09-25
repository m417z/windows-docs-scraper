# ID3D11VideoContext::VideoProcessorGetOutputExtension

## Description

Gets private state data from the video processor.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `pExtensionGuid` [in]

A pointer to a GUID that identifies the state. The meaning of this GUID is defined by the graphics driver.

### `DataSize` [in]

The size of the *pData* buffer, in bytes.

### `pData` [out]

A pointer to a buffer that receives the private state data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)