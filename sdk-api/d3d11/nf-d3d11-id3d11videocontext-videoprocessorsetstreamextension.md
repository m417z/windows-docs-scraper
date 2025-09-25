# ID3D11VideoContext::VideoProcessorSetStreamExtension

## Description

Sets a driver-specific state on a video processing stream.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-createvideoprocessor).

### `StreamIndex` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) and check the **MaxStreamStates** structure member.

### `pExtensionGuid` [in]

A pointer to a GUID that identifies the operation. The meaning of this GUID is defined by the graphics driver.

### `DataSize` [in]

The size of the *pData* buffer, in bytes.

### `pData` [in]

A pointer to a buffer that contains private state data. The method passes this buffer directly to the driver without validation. It is the responsibility of the driver to validate the data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)