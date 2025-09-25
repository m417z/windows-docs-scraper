# IDXVAHD_VideoProcessor::SetVideoProcessStreamState

## Description

Sets a state parameter for an input stream on a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `StreamNumber` [in]

The zero-based index of the input stream. To get the maximum number of streams, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) and check the **MaxStreamStates** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

### `State` [in]

The state parameter to set, specified as a member of the [DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state) enumeration.

### `DataSize` [in]

The size, in bytes, of the buffer pointed to by *pData*.

### `pData` [in]

A pointer to a buffer that contains the state data. The meaning of the data depends on the *State* parameter. Each state has a corresponding data structure; for more information, see [DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state). The caller allocates the buffer and fills in the parameter data before calling this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method to set state parameters that apply to individual input streams.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[IDXVAHD_VideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_videoprocessor)